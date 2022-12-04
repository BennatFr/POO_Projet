#include "DB_Payment.h"

DB_Payment::DB_Payment() {
	this->ID_Payment = 0;
	this->amount = 0;
	this->payment_Date = System::DateTime();
	this->ID_Methode_Payment = 0;
	this->ID_Command = 0;
}

DB_Payment::DB_Payment(int ID_Payment, float amount, System::DateTime payment_Date, int ID_Methode_Payment, int ID_Command) {
	this->ID_Payment = ID_Payment;
	this->amount = amount;
	this->payment_Date = payment_Date;
	this->ID_Methode_Payment = ID_Methode_Payment;
	this->ID_Command = ID_Command;
}

int DB_Payment::getIDPayment() {
	return this->ID_Payment;
}

float DB_Payment::getAmount() {
	return this->amount;
}

System::DateTime DB_Payment::getPaymentDate() {
	return this->payment_Date;
}

int DB_Payment::getIDMethodePayment() {
	return this->ID_Methode_Payment;
}

int DB_Payment::getIDCommand() {
	return this->ID_Command;
}

void DB_Payment::setIDPayment(int ID_Payment) {
	this->ID_Payment = ID_Payment;
}

void DB_Payment::setAmount(float amount) {
	this->amount = amount;
}

void DB_Payment::setPaymentdate(System::DateTime payment_Date) {
	this->payment_Date = payment_Date;
}

void DB_Payment::setIDMethodePayment(int ID_Methode_Payment) {
	this->ID_Methode_Payment = ID_Methode_Payment;
}

void DB_Payment::setIDCommand(int ID_Command) {
	this->ID_Command = ID_Command;
}
