#pragma once
ref class DB_Country {
private:
	int ID_Country;
	System::String^ name;
public:
	DB_Country();
	DB_Country(int ID_Country, System::String^ name);

	~DB_Country();

	int getIDCountry();
	System::String^ getName();

	void setIDCountry(int ID_Country);
	void setName(System::String^ name);

	bool verifName(System::String^ name);
};