#pragma once
ref class DB_Address {
private:
	int ID_Address;
	int street_Number;
	System::String^ street;
	System::String^ additionnal_Data;
	int ID_City;
	int ID_Country;
public:
	DB_Address();
	DB_Address(int ID_Address, int street_Number, System::String^ street, System::String^ additionnal_Data, int ID_City, int ID_Country);

	~DB_Address();

	int getIDAddress();
	int getStreetNumber();
	System::String^ getStreet();
	System::String^ getAdditionnalData();
	int getIDCity();
	int getIDCountry();

	void setIDAddress(int ID_Address);
	void setStreetNumber(int street_Number);
	void setStreet(System::String^ street);
	void setAdditionnalData(System::String^ additionnal_Data);
	void setIDCity(int ID_City);
	void setIDCountry(int ID_Country);
};

