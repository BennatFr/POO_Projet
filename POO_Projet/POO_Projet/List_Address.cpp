#include "List_Address.h"

List_Address::List_Address() {

    this->next = nullptr;
    this->value = nullptr;
}

List_Address::List_Address(Address^ address) {

    this->next = nullptr;
    this->value = address;
}

List_Address::List_Address(List_Address^ listAddress, Address^ address) {

    this->next = listAddress;
    this->value = address;
}

void List_Address::setFirst(Address^ address)
{
    if (this->value == nullptr) {
        this->value = address;
    }
    else if (this->next == nullptr) {
        this->next = gcnew List_Address(this->value);
        this->value = address;
    }
    else {
        List_Address^ tempo = gcnew List_Address(this->next, this->value);
        this->value = address;
        this->next = tempo;
    }
}

void List_Address::setLast(Address^ address) {

    List_Address^ last = getLastList();
    if (last->value == nullptr) {
        this->value = address;
        return;
    }
    List_Address^ tempo = gcnew List_Address(address);
    last->next = tempo;
}

void List_Address::set(Address^ address, int i) {
    if (i == 0) {
        this->setFirst(address);
    } if (i >= this->getSize()) {
        this->setLast(address);
    }
    else {
        List_Address^ get = getList(i - 1);
        List_Address^ tempo = gcnew List_Address(get->next, address);
        get->next = tempo;
    }
}

Address^ List_Address::getFirst()
{
    return this->value;
}

Address^ List_Address::getLast() {
    return this->getLastList()->value;
}

Address^ List_Address::get(int i)
{
    return this->getList(i)->value;
}

List_Address^ List_Address::getLastList()
{
    List_Address^ tempo = this;
    while (tempo->next != nullptr) {
        tempo = tempo->next;
    }
    return tempo;
}

List_Address^ List_Address::getList(int i)
{
    if (i == 0) {
        return this;
    }
    int j = 0;
    List_Address^ tempo = this;
    while (tempo != nullptr && j < i) {
        tempo = tempo->next;
        j = j + 1;
    }
    return tempo;
}

int List_Address::getSize()
{
    int i = 0;
    if (this->value != nullptr) {
        i = 1;
    }
    List_Address^ tempo = this;
    while (tempo->next != nullptr) {
        tempo = tempo->next;
        i = i + 1;
    }
    return i;
}