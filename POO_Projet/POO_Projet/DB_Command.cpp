#include "DB_Command.h"

DB_Command::DB_Command() {
    this->ID_Command = 0;
    this->reference = "";
    this->date_Estimation = System::DateTime();
    this->date_Issue = System::DateTime();
    this->settlement = System::DateTime();
    this->ID_Client = 0;
}

DB_Command::DB_Command(int ID_Command, System::String^ reference, System::DateTime date_Estimation, System::DateTime date_Issue, System::DateTime settlement, int ID_Address_Billing, int ID_Address_Delivery, int ID_Client) {
    this->ID_Command = ID_Command;
    this->reference = reference;
    this->date_Estimation = date_Estimation;
    this->date_Issue = date_Issue;
    this->settlement = settlement;
    this->ID_Address_Billing = ID_Address_Billing;
    this->ID_Address_Delivery = ID_Address_Delivery;
    this->ID_Client = ID_Client;
}

DB_Command::~DB_Command() {
    delete reference;
}

int DB_Command::getIDCommand() {
    return this->ID_Command;
}

System::String^ DB_Command::getReference() {
    return this->reference;
}

System::DateTime DB_Command::getDateEstimation() {
    return this->date_Estimation;
}

System::DateTime DB_Command::getDateIssue() {
    return this->date_Issue;
}

System::DateTime DB_Command::getSettlement() {
    return this->settlement;
}

int DB_Command::getIDAddressBilling() {
    return this->ID_Address_Billing;
}

int DB_Command::getIDAddressDelivery() {
    return this->ID_Address_Delivery;
}

int DB_Command::getIDClient() {
    return this->ID_Client;
}

void DB_Command::setIDCommand(int ID_Command) {
    this->ID_Command = ID_Command;
}

void DB_Command::setReference(System::String^ reference) {
    this->reference = reference;
}

void DB_Command::setDateEstimation(System::DateTime date_Estimation) {
    this->date_Estimation = date_Estimation;
}

void DB_Command::setDateIssue(System::DateTime date_Issue) {
    this->date_Issue = date_Issue;
}

void DB_Command::setSettlement(System::DateTime settlement) {
    this->settlement = settlement;
}

void DB_Command::setIDAddressBilling(int ID_Address_Billing) {
    this->ID_Address_Billing = ID_Address_Billing;
}

void DB_Command::setIDAddressDelivery(int ID_Address_Delivery) {
    this->ID_Address_Delivery = ID_Address_Delivery;
}

void DB_Command::setIDClient(int ID_Client) {
    this->ID_Client = ID_Client;
}
