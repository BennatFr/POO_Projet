#include "Item.h"

Item::Item() {
	this->price = gcnew DB_Price();
	this->item = gcnew DB_Item();
	this->type = gcnew DB_Type();
}

Item::Item(int ID_Item) {
	System::String^ sqlRequest;
	Row^ result;
	sqlRequest = "SELECT * FROM [POO_Projet].[dbo].[Item] WHERE ID_Item = " + ID_Item;
	result = connection->selectRow(sqlRequest, "Item", 0);
	this->item = gcnew DB_Item();
}

Item::Item(int ID_Item, int ID_Command, int row) {
	Item^ item = gcnew Item(ID_Item);
	this->price = item->price;
	this->item = item->item;
	this->type = item->type;
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
