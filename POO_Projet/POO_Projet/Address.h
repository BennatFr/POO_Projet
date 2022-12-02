#pragma once

#include "Connection_DB.h"
#include "DB_Address.h"
#include "DB_City.h"
#include "DB_Country.h"
#include "DB_Client_Address.h"

ref class Address {
private:
	Connection_DB^ connection = gcnew Connection_DB();
	DB_Address^ address;
	DB_City^ city;
	DB_Country^ country;
	DB_Client_Address^ client_Address = nullptr;

	int save();
public:
	Address();
	Address(int idAddress, bool clientAddress);
	Address(DB_Address^ address, DB_City^ city, DB_Country^ country);
	Address(DB_Address^ address, DB_City^ city, DB_Country^ country, DB_Client_Address^ client_Address);

	DB_Address^ getAddress();
	DB_City^ getCity();
	DB_Country^ getCountry();
	DB_Client_Address^ getClientAddress();

	void setAddress(DB_Address^ address);
	void setCity(DB_City^ city);
	void setCountry(DB_Country^ country);
	void setClientAddress(DB_Client_Address^ client_Address);

	void setIDAddress(int id);
	void setIDCountry(int id);
	void setIDCity(int id);

	int insert(int ID_Client);
	int update();
	int del();
};

