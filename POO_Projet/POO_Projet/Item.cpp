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
	///!\ NE GERE ACTUELLEMENT PAS LE CHANGEMENT DE PRIX !!!!
	sqlRequest = "SELECT * FROM Price WHERE ID_Item = " + this->getItem()->getIDItem();
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
	System::String^ sqlRequest = "SELECT * FROM Command_Contain WHERE ID_Item = "+ ID_Item +" AND ID_Command = " + ID_Command;
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
