#pragma once
ref class DB_Client_Address {
private:
	int ID_Client;
	int ID_Address;
	bool is_Billing = false;
public:
	DB_Client_Address();
	DB_Client_Address(int idClient, int idAddress, bool billing);

	int getIdClient();
	int getIdAddress();
	bool isBilling();

	void setIdClient(int id);
	void setIdAddress(int id);
	void setBilling(bool billing);
};

