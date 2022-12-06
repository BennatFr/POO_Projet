#include "Payment.h"

Payment::Payment() {
    this->methode_Payment = gcnew DB_Methode_Payment();
    this->payment = gcnew DB_Payment();
}

Payment::Payment(int ID_Payment) {
    System::String^ sqlRequest;
    Row^ result;

    //DB_Payment
    sqlRequest = "SELECT * FROM Payment WHERE ID_Payment = " + ID_Payment;
    result = connection->selectRow(sqlRequest, "Payment", 0);
    //int ID_Payment, float amount, System::DateTime payment_Date, int ID_Methode_Payment, int ID_Command
    this->payment = gcnew DB_Payment(result->getInt(0), result->getFloat(2), result->getDateTime(1), result->getInt(3), result->getInt(4));

    //DB_Methode_Payment
    sqlRequest = "SELECT * FROM Methode_Payment WHERE ID_Payment_Methode = " + result->getInt(2);
    result = connection->selectRow(sqlRequest, "Methode_Payment", 0);
    //int ID_Methode_Payment, System::String^ type
    this->methode_Payment = gcnew DB_Methode_Payment(result->getInt(0), result->getString(1));
}

Payment::Payment(DB_Methode_Payment^ methode_Payment, DB_Payment^ payment) {
    this->methode_Payment = methode_Payment;
    this->payment = payment;
}

Payment::~Payment() {
    delete connection;
    delete methode_Payment;
    delete payment;
}

int Payment::getIDPayment() {
    return this->getPayment()->getIDPayment();
}

DB_Methode_Payment^ Payment::getMethodePayment() {
    return this->methode_Payment;
}

DB_Payment^ Payment::getPayment() {
    return this->payment;
}

void Payment::setMethodePayment(DB_Methode_Payment^ methode_Payment) {
    this->methode_Payment = methode_Payment;
}

void Payment::setPayment(DB_Payment^ payment) {
    this->payment = payment;
}
