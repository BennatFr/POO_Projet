#pragma once

#include "DB_Command.h"
#include "List_Item.h"
#include "List_Payment.h"

ref class Command {
private:
	Connection_DB^ connection = gcnew Connection_DB();
	DB_Command^ command = gcnew DB_Command();
	List_Item^ list_Item = gcnew List_Item();
	List_Payment^ list_Payment = gcnew List_Payment();
public:
	Command();
	Command(int ID_Command);

	~Command();

	int getCommandID();
	float getCommandPriceHT();
	float getCommandPriceTTC();

	DB_Command^ getCommand();
	List_Item^ getListItem();
	List_Payment^ getListPayment();

	void setCommand(DB_Command^ command);
	void setListItem(List_Item^ list_Item);
	void setListPayment(List_Payment^ list_Payment);

	void setIDCommand(int ID_Command);

	void save();
	int delItem(int ID_Item);
	int delItems();
};

