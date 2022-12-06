#include "Command.h"

Command::Command() {
	this->connection = gcnew Connection_DB();
	this->command = gcnew DB_Command();
	this->list_Item = gcnew List_Item();
	this->list_Payment = gcnew List_Payment();
}

Command::Command(int ID_Command) {
	System::String^ sqlRequest;
	Row^ result;

	//DB_Command
	sqlRequest = "SELECT * FROM Command WHERE ID_Command = " + ID_Command;
	result = connection->selectRow(sqlRequest, "Command", 0);
	//int ID_Command, System::String^ reference, System::DateTime date_Estimation, System::DateTime date_Issue, System::DateTime settlement, int ID_Address_Billing, int ID_Address_Delivery, int ID_Client
	this->command = gcnew DB_Command(result->getInt(0), result->getString(1), result->getDateTime(2), result->getDateTime(3), result->getDateTime(4), result->getInt(5), result->getInt(6), result->getInt(7));

	//List_Item
	sqlRequest = "SELECT * FROM Payment WHERE ID_Command = " + ID_Command;
	System::Data::DataSet^ dataSet = connection->select(sqlRequest, "Payment");
	for (int i = 0; i < dataSet->Tables["Payment"]->Rows->Count; i++) {
		int ID_Payment = System::Convert::ToInt32(dataSet->Tables["Payment"]->Rows[i]->ItemArray[0]->ToString());
		this->list_Payment->setLast(gcnew Payment(ID_Payment));
		this->getListPayment()->getLast()->getPayment()->setIDCommand(ID_Command);
	}

	//List_Item
	sqlRequest = "SELECT * FROM Command_Contain WHERE ID_Command = " + ID_Command;
	dataSet = connection->select(sqlRequest, "Command_Contain");
	for (int i = 0; i < dataSet->Tables["Command_Contain"]->Rows->Count; i++) {
		int ID_Item = System::Convert::ToInt32(dataSet->Tables["Command_Contain"]->Rows[i]->ItemArray[2]->ToString());
		int ID_Command_Contain = System::Convert::ToInt32(dataSet->Tables["Command_Contain"]->Rows[i]->ItemArray[0]->ToString());
		float quantity = (float) System::Convert::ToDecimal(dataSet->Tables["Command_Contain"]->Rows[i]->ItemArray[3]->ToString());
		float discount = (float) System::Convert::ToDecimal(dataSet->Tables["Command_Contain"]->Rows[i]->ItemArray[4]->ToString());
		this->list_Item->setLast(gcnew Item(ID_Item));
		this->getListItem()->getLast()->getCommandContain()->setIDCommand(ID_Command);
		this->getListItem()->getLast()->getCommandContain()->setIDContain(ID_Command_Contain);
		this->getListItem()->getLast()->getCommandContain()->setQuantity(quantity);
		this->getListItem()->getLast()->getCommandContain()->setDiscount(discount);
	}
}

int Command::getCommandID() {
	return this->command->getIDCommand();
}

float Command::getCommandPriceHT() {
	float price = 0;
	for (int i = 0; i < this->getListItem()->getSize(); i++) {
		price += this->getListItem()->get(i)->getFloatPriceHT();
	}
	return price;
}

float Command::getCommandPriceTTC() {
	float price = 0;
	for (int i = 0; i < this->getListItem()->getSize(); i++) {
		price += this->getListItem()->get(i)->getFloatPriceTTC();
	}
	return price;
}

DB_Command^ Command::getCommand() {
	return this->command;
}

List_Item^ Command::getListItem() {
	return this->list_Item;
}

List_Payment^ Command::getListPayment() {
	return this->list_Payment;
}

void Command::setCommand(DB_Command^ command) {
	this->command = command;
}

void Command::setListItem(List_Item^ list_Item) {
	this->list_Payment = list_Payment;
}

void Command::setListPayment(List_Payment^ list_Payment) {
	this->list_Item = list_Item;
}

void Command::setIDCommand(int ID_Command) {
	this->getCommand()->setIDCommand(ID_Command);
	for (int i = 0; i < this->list_Payment->getSize(); i++) {
		this->list_Payment->get(i)->getPayment()->setIDCommand(ID_Command);
	}

	for (int i = 0; i < this->list_Item->getSize(); i++) {
		this->list_Item->get(i)->getCommandContain()->setIDCommand(ID_Command);
	}
}

void Command::save() {
	System::String^ sqlRequest;
	Row^ result;
	if (this->getCommandID() == 0) {
		sqlRequest = "INSERT INTO Command VALUES ( '" + this->getCommand()->getReference() + "', '" + this->getCommand()->getDateEstimation() + "', '" + this->getCommand()->getDateIssue() + "','" + this->getCommand()->getSettlement() + "'," + this->getCommand()->getIDAddressDelivery() + "," + this->getCommand()->getIDAddressBilling() + "," + this->getCommand()->getIDClient() + ")";
		connection->execute(sqlRequest);
		sqlRequest = "SELECT TOP 1 * FROM Command ORDER BY ID_Command DESC";
		result = connection->selectRow(sqlRequest, "Command", 0);
		this->setIDCommand(result->getInt(0));

		for (int i = 0; i < this->getListItem()->getSize(); i++) {
			Item^ item = this->getListItem()->get(i);
			sqlRequest = "INSERT INTO Command_Contain VALUES (" + this->getCommandID() + ", " + item->getItemID() + ", " + item->getCommandContain()->getQuantity().ToString()->Replace(",", ".") + ", " + item->getCommandContain()->getDiscount().ToString()->Replace(",", ".") + ")";
			connection->execute(sqlRequest);
		}

		for (int i = 0; i < this->getListPayment()->getSize(); i++) {
			Payment^ payment = this->getListPayment()->get(i);
			sqlRequest = "INSERT INTO Payment VALUES ('" + payment->getPayment()->getPaymentDate() + "', " + payment->getPayment()->getAmount() + ", " + payment->getMethodePayment()->getIDMethodePayment() + ", "+ payment->getPayment()->getIDCommand() + ")";
			connection->execute(sqlRequest);
		}
	}
}
