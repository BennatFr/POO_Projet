#pragma once
ref class DB_People {
private:
	int ID_People;
	System::String^ last_Name;
	System::String^ first_Name;
public:
	DB_People();
	DB_People(int ID_People, System::String^ last_Name, System::String^ first_Name);

	int getIDPeople();
	System::String^ getLastName();
	System::String^ getFirstName();

	void setIDPeople(int ID_People);
	void getLastName(System::String^ last_Name);
	void getFirstName(System::String^ first_Name);
};

