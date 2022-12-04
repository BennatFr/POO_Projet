#pragma once
ref class DB_Methode_Payment {
private:
	int ID_Methode_Payment;
	System::String^ type;
public:
	DB_Methode_Payment();
	DB_Methode_Payment(int ID_Methode_Payment, System::String^ type);

	int getIDMethodePayment();
	System::String^ getType();

	void setIDMethodePayment(int ID_Methode_Payment);
	void setType(System::String^ type);
};