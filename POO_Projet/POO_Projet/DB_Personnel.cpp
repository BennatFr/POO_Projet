#include "DB_Personnel.h"

DB_Personnel::DB_Personnel() {
    this->ID_Personnel = 0;
    this->hire_Date = System::DateTime();
    this->ID_Address = 0;
    this->ID_Superior = 0;
    this->ID_People = 0;
}

DB_Personnel::DB_Personnel(int ID_Personnel, System::DateTime hire_Date, int ID_Address, int ID_Superior, int ID_People) {
    this->ID_Personnel = ID_Personnel;
    this->hire_Date = hire_Date;
    this->ID_Address = ID_Address;
    this->ID_Superior = ID_Superior;
    this->ID_People = ID_People;
}

DB_Personnel::~DB_Personnel() {
    throw gcnew System::NotImplementedException();
}

int DB_Personnel::getIDPersonnel() {
    return this->ID_Personnel;
}

System::DateTime DB_Personnel::getHireDate() {
    return this->hire_Date;
}

int DB_Personnel::getIDAddress() {
    return this->ID_Address;
}

int DB_Personnel::getIDSuperior() {
    return this->ID_Superior;
}

int DB_Personnel::getIDPeople() {
    return this->ID_People;
}

void DB_Personnel::setIDPersonnel(int ID_Personnel) {
    this->ID_Personnel = ID_Personnel;
}

void DB_Personnel::setHireDate(System::DateTime hire_Date) {
    this->hire_Date = hire_Date;
}

void DB_Personnel::setIDAddress(int ID_Address) {
    this->ID_Address = ID_Address;
}

void DB_Personnel::setIDSuperior(int ID_Superior) {
    this->ID_Superior = ID_Superior;
}

void DB_Personnel::setIDPeople(int ID_People) {
    this->ID_People = ID_People;
}
