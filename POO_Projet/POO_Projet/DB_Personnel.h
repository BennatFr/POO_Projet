#pragma once

ref class DB_Personnel {
private:
	int ID_Personnel;
	System::String^ hire_Date;
	int ID_Address;
	int ID_Superior;
	int ID_People;
public:
	DB_Personnel();
	DB_Personnel(int ID_Personnel, System::String^ hire_Date, int ID_Address, int ID_Superior, int ID_People);

	~DB_Personnel();

	int getIDPersonnel();
	System::String^ getHireDate();
	int getIDAddress();
	int getIDSuperior();
	int getIDPeople();

	void setIDPersonnel(int ID_Personnel);
	void setHireDate(System::String^ hire_Date);
	void setIDAddress(int ID_Address);
	void setIDSuperior(int ID_Superior);
	void setIDPeople(int ID_People);
};

