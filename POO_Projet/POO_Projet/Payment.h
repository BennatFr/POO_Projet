#pragma once

#include "Connection_DB.h"
#include "DB_Methode_Payment.h"
#include "DB_Payment.h"

ref class Payment {
private:
	Connection_DB^ connection = gcnew Connection_DB();
	DB_Methode_Payment^ methode_Payment = gcnew DB_Methode_Payment();
	DB_Payment^ payment = gcnew DB_Payment();
public:
	Payment();
	Payment(int ID_Payment);
	Payment(DB_Methode_Payment^ methode_Payment, DB_Payment^ payment);

	~Payment();

	int getIDPayment();
	DB_Methode_Payment^ getMethodePayment();
	DB_Payment^ getPayment();

	void setMethodePayment(DB_Methode_Payment^ methode_Payment);
	void setPayment(DB_Payment^ payment);

	/*int insert();
	int update();
	int del();*/
};


