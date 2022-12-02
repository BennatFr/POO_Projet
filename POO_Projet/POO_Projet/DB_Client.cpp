#include "DB_Client.h"

DB_Client::DB_Client() {
	this->ID_Client = 0;
	this->birthdate = System::DateTime(System::DateTime::Today);
	this->first_Buy_Website = System::DateTime(System::DateTime::Today);
	this->ID_People = 0;
}

DB_Client::DB_Client(int ID_Client, System::DateTime birthdate, System::DateTime first_Buy_Website, int ID_People) {
	this->ID_Client = ID_Client;
	this->birthdate = birthdate;
	this->first_Buy_Website = first_Buy_Website;
	this->ID_People = ID_People;
}

int DB_Client::getIDClient() {
	return this->ID_Client;
}

System::DateTime DB_Client::getBirthdate() {
	return this->birthdate;
}

System::DateTime DB_Client::getFirstBuyWebsite() {
	return this->first_Buy_Website;
}

int DB_Client::getIDPeople() {
	return this->ID_People;
}

void DB_Client::setIDClient(int ID_Client) {
	this->ID_Client = ID_Client;
}

void DB_Client::setBirthdate(System::DateTime birthdate) {
	this->birthdate = birthdate;
}

void DB_Client::setFirstBuyWebsite(System::DateTime first_Buy_Website) {
	this->first_Buy_Website = first_Buy_Website;
}

void DB_Client::setIDPeople(int ID_People) {
	this->ID_People = ID_People;
}
