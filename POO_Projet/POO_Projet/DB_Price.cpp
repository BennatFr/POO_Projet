#include "DB_Price.h"

DB_Price::DB_Price() {
	this->ID_Price = 0;
	this->price = 0.0f;
	this->VAT = 0.0f;
	this->date_Price = System::DateTime();
	this->ID_Item = 0;
}

DB_Price::DB_Price(int ID_Price, float price, float VAT, System::DateTime date_Price, int ID_Item) {
	this->ID_Price = ID_Price;
	this->price = price;
	this->VAT = VAT;
	this->date_Price = date_Price;
	this->ID_Item = ID_Item;
}

int DB_Price::getIDPrice() {
	return this->ID_Price;
}

float DB_Price::getPrice() {
	return this->price;
}

float DB_Price::getVAT() {
	return this->VAT;
}

System::DateTime DB_Price::getDatePrice() {
	return this->date_Price;
}

int DB_Price::getIDItem() {
	return this->ID_Item;
}

void DB_Price::setIDPrice(int ID_Price) {
	this->ID_Price = ID_Price;
}

void DB_Price::setPrice(float price) {
	this->price = price;
}

void DB_Price::setVAT(float VAT) {
	this->VAT = VAT;
}

void DB_Price::setDatePrice(System::DateTime date_Price) {
	this->date_Price = date_Price;
}

void DB_Price::setIDItem(int ID_Item) {
	this->ID_Item = ID_Item;
}
