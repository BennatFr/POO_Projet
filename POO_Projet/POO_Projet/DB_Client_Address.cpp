#include "DB_Client_Address.h"

DB_Client_Address::DB_Client_Address() {
    this->ID_Client = 0;
    this->ID_Address = 0;
    this->is_Billing = false;
}

DB_Client_Address::DB_Client_Address(int idClient, int idAddress, bool billing) {
    this->ID_Client = idClient;
    this->ID_Address = idAddress;
    this->is_Billing = billing;
}

int DB_Client_Address::getIdClient() {
    return this->ID_Client;
}

int DB_Client_Address::getIdAddress() {
    return this->ID_Address;
}

bool DB_Client_Address::isBilling() {
    return this->is_Billing;
}

void DB_Client_Address::setIdClient(int id) {
    this->ID_Client = id;
}

void DB_Client_Address::setIdAddress(int id) {
    this->ID_Address = id;
}

void DB_Client_Address::setBilling(bool billing) {
    this->is_Billing= billing;
}
