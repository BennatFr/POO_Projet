#pragma once

#include "DB_Client.h";
#include "DB_People.h";
#include "List_Address.h";

ref class Client {
private:
	Connection_DB^ connection = gcnew Connection_DB();
	DB_Client^ client = gcnew DB_Client();
	DB_People^ people = gcnew DB_People();
	List_Address^ list_Address = gcnew List_Address();
public:
	Client();
	Client(int ID_Client);

	DB_Client^ getClient();
	DB_People^ getPeople();
	List_Address^ getListAddress();

	void setClient(DB_Client^ client);
	void setPeople(DB_People^ people);
	void setListAddress(List_Address^ list_Address);

	void setIDPeople(int ID_People);
	void setIDAddress(int ID_Address);

	int insert();
	int update();
	int del();

	int insertWithAddress();
	int updateWithAddress();
	int delWithAddress();
};

