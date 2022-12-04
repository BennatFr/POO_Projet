#include "Command.h"

Command::Command() {
    this->connection = gcnew Connection_DB();
    this->command = gcnew DB_Command();
    this->list_Item = gcnew List_Item();
    this->list_Payment = gcnew List_Payment();
}

Command::Command(int ID_Command) {
    throw gcnew System::NotImplementedException();
}

int Command::getCommandID() {
    return this->command->getIDCommand();
}

float Command::getCommandPriceHT() {
    float price = 0;
    for (int i = 0; i < this->getListItem()->getSize(); i++) {
        price += this->getListItem()->get(i)->getFloatPriceHT();
    }
    return price;
}

float Command::getCommandPriceTTC() {
    float price = 0;
    for (int i = 0; i < this->getListItem()->getSize(); i++) {
        price += this->getListItem()->get(i)->getFloatPriceTTC();
    }
    return price;
}

DB_Command^ Command::getCommand() {
    return this->command;
}

List_Item^ Command::getListItem() {
    return this->list_Item;
}

List_Payment^ Command::getListPayment() {
    return this->list_Payment;
}

void Command::setCommand(DB_Command^ command) {
    this->command = command;
}

void Command::setListItem(List_Item^ list_Item) {
    this->list_Payment = list_Payment;
}

void Command::setListPayment(List_Payment^ list_Payment) {
    this->list_Item = list_Item;
}

void Command::setIDCommand(int ID_Command) {
    throw gcnew System::NotImplementedException();
}
