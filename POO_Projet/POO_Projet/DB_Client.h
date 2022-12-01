#pragma once
ref class DB_Client {
private:
	int ID_Client;
	System::DateTime birthdate;
	System::DateTime first_Buy_Website;
	int ID_People;
public:
	DB_Client();
	DB_Client(int ID_Client, System::DateTime birthdate, System::DateTime first_Buy_Website, int ID_People);
	
	int getIDClient();
	System::DateTime getBirthdate();
	System::DateTime getFirstBuyWebsite();
	int getIDPeople();

	void setIDClient(int ID_Client);
	void setBirthdate(System::DateTime birthdate);
	void setFirstBuyWebsite(System::DateTime first_Buy_Website);
	void setIDPeople(int ID_People);
};

