#pragma once

#include "Connection_DB.h"
#include "DB_Personnel.h"
#include "DB_Address.h"
#include "DB_City.h"
#include "DB_Country.h"
#include "DB_People.h"

ref class Personnel {
private:
	Connection_DB^ connection;
	DB_Personnel^ personnel = gcnew DB_Personnel();
	DB_Address^ address = gcnew DB_Address();
	DB_City^ city = gcnew DB_City();
	DB_Country^ country = gcnew DB_Country();
	DB_People^ people = gcnew DB_People();
public:
	Personnel();
	Personnel(System::String^ ID_Personnel);

	int getPersonnelID();
	DB_Personnel^ getPersonnel();
	DB_Address^ getAddress();
	DB_City^ getCity();
	DB_Country^ getCountry();
	DB_People^ getPeople();
};


