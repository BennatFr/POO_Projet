#include "DB_Address.h"

DB_Address::DB_Address() {
	this->ID_Address = 0;
	this->street_Number = 0;
	this->street = "";
	this->additionnal_Data = "";
	this->ID_City = 0;
	this->ID_Country = 0;
}

DB_Address::DB_Address(int ID_Address, int street_Number, System::String^ street, System::String^ additionnal_Data, int ID_City, int ID_Country) {
	this->ID_Address = ID_Address;
	this->street_Number = street_Number;
	this->street = street;
	this->additionnal_Data = additionnal_Data;
	this->ID_City = ID_City;
	this->ID_Country = ID_Country;
}

DB_Address::~DB_Address() {
	delete street;
	delete additionnal_Data;
}

int DB_Address::getIDAddress() {
	return this->ID_Address;
}

int DB_Address::getStreetNumber() {
	return this->street_Number;
}

System::String^ DB_Address::getStreet() {
	return this->street;
}

System::String^ DB_Address::getAdditionnalData() {
	return this->additionnal_Data;
}

int DB_Address::getIDCity() {
	return this->ID_City;
}

int DB_Address::getIDCountry() {
	return this->ID_Country;
}

void DB_Address::setIDAddress(int ID_Address) {
	this->ID_Address = ID_Address;
}

void DB_Address::setStreetNumber(int street_Number) {
	this->street_Number = street_Number;
}

void DB_Address::setStreet(System::String^ street) {
	this->street = street;
}

void DB_Address::setAdditionnalData(System::String^ additionnal_Data) {
	this->additionnal_Data = additionnal_Data;
}

void DB_Address::setIDCity(int ID_City) {
	this->ID_City = ID_City;
}

void DB_Address::setIDCountry(int ID_Country) {
	this->ID_Country = ID_Country;
}
