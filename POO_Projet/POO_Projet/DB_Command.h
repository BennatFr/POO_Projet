#pragma once
ref class DB_Command {
private:
	int ID_Command;
	System::String^ reference;
	System::DateTime date_Estimation;
	System::DateTime date_Issue;
	System::DateTime settlement;
	int ID_Address_Billing;
	int ID_Address_Delivery;
	int ID_Client;
public:
	DB_Command();
	DB_Command(int ID_Command, System::String^ reference, System::DateTime date_Estimation, System::DateTime date_Issue, System::DateTime settlement, int ID_Address_Billing, int ID_Address_Delivery, int ID_Client);

	~DB_Command();

	int getIDCommand();
	System::String^ getReference();
	System::DateTime getDateEstimation();
	System::DateTime getDateIssue();
	System::DateTime getSettlement();
	int getIDAddressBilling();
	int getIDAddressDelivery();
	int getIDClient();

	void setIDCommand(int ID_Command);
	void setReference(System::String^ reference);
	void setDateEstimation(System::DateTime date_Estimation);
	void setDateIssue(System::DateTime date_Issue);
	void setSettlement(System::DateTime settlement);
	void setIDAddressBilling(int ID_Address_Billing);
	void setIDAddressDelivery(int ID_Address_Delivery);
	void setIDClient(int ID_Client);
};

