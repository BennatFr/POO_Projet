#include "DB_Command_Contain.h"

DB_Command_Contain::DB_Command_Contain() {
	this->ID_Contain = 0;
	this->ID_Command = 0;
	this->ID_Item = 0;
	this->quantity = 0.0f;
	this->discount = 0.0f;
}

DB_Command_Contain::DB_Command_Contain(int ID_Contain, int ID_Command, int ID_Item, float quantity, float discount) {
	this->ID_Contain = ID_Contain;
	this->ID_Command = ID_Command;
	this->ID_Item = ID_Item;
	this->quantity = quantity;
	this->discount = discount;
}

int DB_Command_Contain::getIDContain() {
	return this->ID_Contain;
}

int DB_Command_Contain::getIDCommand() {
	return this->ID_Command;
}

int DB_Command_Contain::getIDItem() {
	return this->ID_Item;
}

float DB_Command_Contain::getQuantity() {
	return this->quantity;
}

float DB_Command_Contain::getDiscount() {
	return this->discount;
}

void DB_Command_Contain::setIDContain(int ID_Contain) {
	this->ID_Contain = ID_Contain;
}

void DB_Command_Contain::setIDCommand(int ID_Command) {
	this->ID_Command = ID_Command;
}

void DB_Command_Contain::setIDItem(int ID_Item) {
	this->ID_Item = ID_Item;
}

void DB_Command_Contain::setQuantity(float quantity) {
	this->quantity = quantity;
}

void DB_Command_Contain::setDiscount(float discount) {
	this->discount = discount;
}
