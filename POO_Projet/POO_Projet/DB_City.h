#pragma once
ref class DB_City {
private:
	int ID_City;
	System::String^ name;
	System::String^ postal_number;
public:
	DB_City();
	DB_City(int ID_City, System::String^ name, System::String^ postal_number);

	~DB_City();

	int getIDCity();
	System::String^ getName();
	System::String^ getPostalNumber();

	void setIDCity(int ID_City);
	void setName(System::String^ name);
	void setPostalNumber(System::String^ postal_number);

	bool verifName(System::String^ name);
	bool verifPostalNumber(System::String^ postal_number);
};

