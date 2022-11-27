#pragma once

#include "Connection_DB.h"
#include "DB_Personnel.h"
#include "DB_Address.h"

ref class Personnel {
private:
	Connection_DB^ connection;
	DB_Personnel^ personnel = gcnew DB_Personnel();
	DB_Address^ address = gcnew DB_Address();
public:
	Personnel();
	Personnel(System::String^ ID_Personnel);

	int getPersonnelID();
	DB_Personnel^ getPersonnel();
	DB_Address^ getAddress();
};


