#include "DB_Type.h"

DB_Type::DB_Type() {
	this->ID_Type = 0;
	this->name = "";
}

DB_Type::DB_Type(int ID_Type, System::String^ name) {
	this->ID_Type = ID_Type;
	this->name = name;
}

int DB_Type::getIDType() {
	return this->ID_Type;
}

System::String^ DB_Type::getName() {
	return this->name;
}

void DB_Type::setIDType(int ID_Type) {
	this->ID_Type = ID_Type;
}

void DB_Type::setName(System::String^ name) {
	this->name = name;
}
