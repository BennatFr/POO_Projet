#include "DB_Item.h"

DB_Item::DB_Item() {
	this->ID_Item = 0;
	this->reference = "";
	this->name = "";
	this->replenishment = 0.0f;
	this->stock = 0.0f;
	this->quantity = 0.0f;
	this->discount = 0.0f;
	this->ID_Type = 0;
}

DB_Item::DB_Item(int ID_Item, System::String^ reference, System::String^ name, float replenishment, float stock, float quantity, float discount, int ID_Type) {
	this->ID_Item = ID_Item;
	this->reference = reference;
	this->name = name;
	this->replenishment = replenishment;
	this->stock = stock;
	this->quantity = quantity;
	this->discount = discount;
	this->ID_Type = ID_Type;
}

int DB_Item::getIDItem() {
	return this->ID_Item;
}

System::String^ DB_Item::getReference() {
	return this->reference;
}

System::String^ DB_Item::getName() {
	return this->name;
}

float DB_Item::getReplenishment() {
	this->replenishment;
}

float DB_Item::getStock() {
	this->stock;
}

float DB_Item::getQuantity() {
	this->quantity;
}

float DB_Item::getDiscount() {
	this->discount;
}

int DB_Item::getIDType() {
	this->ID_Type;
}

void DB_Item::setIDItem(int ID_Item) {
	this->ID_Item = ID_Item;
}

void DB_Item::setReference(System::String^ reference) {
	this->reference = reference;
}

void DB_Item::setName(System::String^ name) {
	this->name = name;
}

void DB_Item::setReplenishment(float replenishment) {
	this->replenishment = replenishment;
}

void DB_Item::setStock(float stock) {
	this->stock = stock;
}

void DB_Item::setQuantity(float quantity) {
	this->quantity = quantity;
}

void DB_Item::setDiscount(float discount) {
	this->discount = discount;
}

void DB_Item::setIDType(int ID_Type) {
	this->ID_Type = ID_Type;
}
