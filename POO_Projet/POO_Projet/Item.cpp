#include "Item.h"

Item::Item() {
	this->price = gcnew DB_Price();
	this->item = gcnew DB_Item();
	this->type = gcnew DB_Type();
}

Item::Item(int ID_Item) {
	System::String^ sqlRequest;
	Row^ result;

	//DB_Item
	sqlRequest = "SELECT * FROM [POO_Projet].[dbo].[Item] WHERE ID_Item = " + ID_Item;
	result = connection->selectRow(sqlRequest, "Item", 0);
	//int ID_Item, System::String^ reference, System::String^ name, float replenishment, float stock, float quantity, float discount, int ID_Type
	this->item = gcnew DB_Item(result->getInt(0), result->getString(1), result->getString(2), result->getFloat(3), result->getFloat(4), 0.0f, 0.0f, result->getInt(5));

	//DB_Type
	sqlRequest = "SELECT * FROM Type WHERE ID_Type = " + this->getItem()->getIDType();
	result = connection->selectRow(sqlRequest, "Type", 0);
	//int ID_Type, System::String^ name
	this->type = gcnew DB_Type(this->getItem()->getIDType(), result->getString(1));

	//DB_Price
	sqlRequest = "SELECT top 1 * FROM Price WHERE ID_Item = " + this->getItem()->getIDItem() + " ORDER BY date_Price DESC";
	result = connection->selectRow(sqlRequest, "Price", 0);
	//int ID_Price, float price, float VAT, System::DateTime date_Price, int ID_Item
	this->price = gcnew DB_Price(result->getInt(0), result->getFloat(1), result->getFloat(2), result->getDateTime(3), result->getInt(4));
}

Item::Item(int ID_Item, int ID_Command, int row) {
	Item^ item = gcnew Item(ID_Item);
	this->price = item->price;
	this->item = item->item;
	this->type = item->type;

	//Command_Contain
	System::String^ sqlRequest = "SELECT * FROM Command_Contain WHERE ID_Item = " + ID_Item + " AND ID_Command = " + ID_Command;
	Row^ result = connection->selectRow(sqlRequest, "Item", row);

	this->item->setQuantity(0.0f);
	this->item->setDiscount(0.0f);
}

Item::Item(DB_Price^ price, DB_Item^ item, DB_Type^ type) {
	this->price = price;
	this->item = item;
	this->type = type;
}

DB_Price^ Item::getPrice() {
	return this->price;
}

DB_Item^ Item::getItem() {
	return this->item;
}

DB_Type^ Item::getType() {
	return this->type;
}

void Item::setPrice(DB_Price^ price) {
	this->price = price;
}

void Item::setItem(DB_Item^ item) {
	this->item = item;
}

void Item::setType(DB_Type^ type) {
	this->type = type;
}

int Item::getItemID()
{
	return this->getItem()->getIDItem();
}

void Item::setIDType(int ID_Type)
{
	this->getType()->setIDType(ID_Type);
	this->getItem()->setIDType(ID_Type);
}

void Item::setIDItem(int ID_Item)
{
	this->getItem()->setIDItem(ID_Item);
	this->getPrice()->setIDItem(ID_Item);
}

int Item::insert()
{
	System::String^ sqlRequest;
	Row^ result;
	sqlRequest = "SELECT Count(*) FROM Item WHERE ID_Item = " + this->getItemID();
	result = connection->selectRow(sqlRequest, "Item", 0);
	if (result->getInt(0) != 0) {
		return 1;
	}
	if (this->GetType() != nullptr) {
		sqlRequest = "SELECT Count(*) FROM Type WHERE name = '" + this->getType()->getName() + "'";
		result = connection->selectRow(sqlRequest, "Item", 0);
		if (result->getInt(0) == 0) {
			sqlRequest = "INSERT INTO Type VALUES ('" + this->getType()->getName() + "')";
			connection->execute(sqlRequest);
			sqlRequest = "SELECT TOP 1 * FROM Type ORDER BY ID_Type DESC";
			result = connection->selectRow(sqlRequest, "Type", 0);
			this->setIDType(result->getInt(0));
		} else {
			sqlRequest = "SELECT * FROM Type WHERE name = '" + this->getType()->getName() + "'";
			result = connection->selectRow(sqlRequest, "Type", 0);
			this->setIDType(result->getInt(0));
		}
	}

	if (this->getItem() != nullptr) {
		sqlRequest = "INSERT INTO Item VALUES ('" + this->getItem()->getReference() + "', '" + this->getItem()->getName() + "', " + this->getItem()->getReplenishment().ToString()->Replace(",", ".") + ", " + this->getItem()->getStock().ToString()->Replace(",", ".") + ", " + this->getItem()->getIDType() + ")";
		connection->execute(sqlRequest);
		sqlRequest = "SELECT TOP 1 * FROM Item ORDER BY ID_Item DESC";
		result = connection->selectRow(sqlRequest, "Type", 0);
		this->setIDItem(result->getInt(0));
	}

	if (this->getPrice() != nullptr) {
		sqlRequest = "INSERT INTO Price VALUES (" + this->getPrice()->getPrice().ToString()->Replace(",", ".") + ", " + this->getPrice()->getVAT().ToString()->Replace(",", ".") + ", '" + this->getPrice()->getDatePrice() + "', " + this->getPrice()->getIDItem() + ")";
		connection->execute(sqlRequest);
		sqlRequest = "SELECT TOP 1 * FROM Price ORDER BY ID_Price DESC";
		result = connection->selectRow(sqlRequest, "Type", 0);
		this->setIDType(result->getInt(0));
	}
	return 0;
}

int Item::update() {
	System::String^ sqlRequest;
	Row^ result;
	sqlRequest = "SELECT Count(*) FROM Item WHERE ID_Item = " + this->getItemID();
	result = connection->selectRow(sqlRequest, "Item", 0);
	if (result->getInt(0) == 0) {
		return 1;
	}

	if (this->GetType() != nullptr) {
		sqlRequest = "SELECT Count(*) FROM Type WHERE name = '" + this->getType()->getName() + "'";
		result = connection->selectRow(sqlRequest, "Item", 0);
		if (result->getInt(0) == 0) {
			sqlRequest = "INSERT INTO Type VALUES ('" + this->getType()->getName() + "')";
			connection->execute(sqlRequest);
			sqlRequest = "SELECT TOP 1 * FROM Type ORDER BY ID_Type DESC";
			result = connection->selectRow(sqlRequest, "Type", 0);
			this->setIDType(result->getInt(0));
		} else {
			sqlRequest = "SELECT * FROM Type WHERE name = '" + this->getType()->getName() + "'";
			result = connection->selectRow(sqlRequest, "Type", 0);
			this->setIDType(result->getInt(0));
		}
	}

	if (this->getItem() != nullptr) {
		sqlRequest = "UPDATE Item set name = '"+ this->getItem()->getName() +"', reference = '"+ this->getItem()->getReference() +"', replenishment = "+ this->getItem()->getReplenishment().ToString()->Replace(",", ".") +", stock = "+ this->getItem()->getStock().ToString()->Replace(",", ".") +", ID_Type =" + this->getItem()->getIDType();
		connection->execute(sqlRequest);
	}

	if (this->getPrice() != nullptr) {
		sqlRequest = "INSERT INTO Price VALUES (" + this->getPrice()->getPrice().ToString()->Replace(",", ".") + ", " + this->getPrice()->getVAT().ToString()->Replace(",", ".") + ", '" + this->getPrice()->getDatePrice() + "', " + this->getPrice()->getIDItem() + ")";
		connection->execute(sqlRequest);
	}
	return 0;
}
