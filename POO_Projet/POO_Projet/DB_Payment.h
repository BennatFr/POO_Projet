#pragma once
ref class DB_Payment {
private:
	int ID_Payment;
	float amount;
	System::DateTime payment_Date;
	int ID_Methode_Payment;
	int ID_Command;
public:
	DB_Payment();
	DB_Payment(int ID_Payment, float amount, System::DateTime payment_Date, int ID_Methode_Payment, int ID_Command);

	int getIDPayment();
	float getAmount();
	System::DateTime getPaymentDate();
	int getIDMethodePayment();
	int getIDCommand();

	void setIDPayment(int ID_Payment);
	void setAmount(float amount);
	void setPaymentdate(System::DateTime payment_Date);
	void setIDMethodePayment(int ID_Methode_Payment);
	void setIDCommand(int ID_Command);
};

