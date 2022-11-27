#pragma once

#include <string>

using namespace std;

ref class BD_Personnel {
private:
	int ID_Personnel;
	int hire_Date;
	int ID_Address;
	int ID_Superior;
	int ID_People;
public:
	BD_Personnel();
	BD_Personnel(int ID_Personnel, int hire_Date, int ID_Address, int ID_Superior, int ID_People);

	~BD_Personnel();

	int getIDPersonnel();
	int getHireDate();
	int getIDAddress();
	int getIDSuperior();
	int getIDPeople();

	void setIDPersonnel(int ID_Personnel);
	void setHireDate(int hire_Date);
	void setIDAddress(int ID_Address);
	void setIDSuperior(int ID_Superior);
	void setIDPeople(int ID_People);
};

