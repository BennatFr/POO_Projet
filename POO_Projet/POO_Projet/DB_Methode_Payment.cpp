#include "DB_Methode_Payment.h"

DB_Methode_Payment::DB_Methode_Payment() {
	this->ID_Methode_Payment = 0;
	this->type = "";
}

DB_Methode_Payment::DB_Methode_Payment(int ID_Methode_Payment, System::String^ type) {
	this->ID_Methode_Payment = ID_Methode_Payment;
	this->type = type;
}

int DB_Methode_Payment::getIDMethodePayment() {
	return this->ID_Methode_Payment;
}

System::String^ DB_Methode_Payment::getType()
{
	return this->type;
}

void DB_Methode_Payment::setIDMethodePayment(int ID_Methode_Payment)
{
	this->ID_Methode_Payment = ID_Methode_Payment;
}

void DB_Methode_Payment::setType(System::String^ type)
{
	this->type = type;
}
