#pragma once

#include "Connection_DB.h"
#include "DB_Personnel.h"
#include "Address.h"
#include "DB_People.h"

ref class Personnel {
private:
	Connection_DB^ connection = gcnew Connection_DB();
	DB_Personnel^ personnel = gcnew DB_Personnel();
	Address^ address = gcnew Address();
	DB_People^ people = gcnew DB_People();
public:
	Personnel();
	Personnel(int ID_Personnel);
	Personnel(DB_Personnel^ personnel, Address^ address, DB_People^ people);

	~Personnel();

	int getPersonnelID();
	DB_Personnel^ getPersonnel();
	Address^ getAddress();
	DB_People^ getPeople();

	void setPersonnel(DB_Personnel^);
	void setAddress(Address^);
	void setPeople(DB_People^);

	void setIDPeople(int ID_People);
	void setIDAddress(int ID_Address);

	int insert();
	int update();
	int del();
};