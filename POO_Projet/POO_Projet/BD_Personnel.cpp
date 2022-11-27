#include "BD_Personnel.h"

BD_Personnel::BD_Personnel() {
    this->ID_Personnel = 0;
    this->hire_Date = 0;
    this->ID_Address = 0;
    this->ID_Superior = 0;
    this->ID_People = 0;
}

BD_Personnel::BD_Personnel(int ID_Personnel, int hire_Date, int ID_Address, int ID_Superior, int ID_People) {
    this->ID_Personnel = ID_Personnel;
    this->hire_Date = hire_Date;
    this->ID_Address = ID_Address;
    this->ID_Superior = ID_Superior;
    this->ID_People = ID_People;
}

BD_Personnel::~BD_Personnel() {
    throw gcnew System::NotImplementedException();
}

int BD_Personnel::getIDPersonnel() {
    return this->ID_Personnel;
}

int BD_Personnel::getHireDate() {
    return this->hire_Date;
}

int BD_Personnel::getIDAddress() {
    return this->ID_Address;
}

int BD_Personnel::getIDSuperior() {
    return this->ID_Superior;
}

int BD_Personnel::getIDPeople() {
    return this->ID_People;
}

void BD_Personnel::setIDPersonnel(int ID_Personnel) {
    this->ID_Personnel = ID_Personnel;
}

void BD_Personnel::setHireDate(int hire_Date) {
    this->hire_Date = hire_Date;
}

void BD_Personnel::setIDAddress(int ID_Address) {
    this->ID_Address = ID_Address;
}

void BD_Personnel::setIDSuperior(int ID_Superior) {
    this->ID_Superior = ID_Superior;
}

void BD_Personnel::setIDPeople(int ID_People) {
    this->ID_People = ID_People;
}
