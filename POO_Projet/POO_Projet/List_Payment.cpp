#include "List_Payment.h"

List_Payment::List_Payment() {

    this->next = nullptr;
    this->value = nullptr;
}

List_Payment::List_Payment(Payment^ payment) {

    this->next = nullptr;
    this->value = payment;
}

List_Payment::List_Payment(List_Payment^ listPayment, Payment^ payment) {

    this->next = listPayment;
    this->value = payment;
}

void List_Payment::setFirst(Payment^ payment) {
    if (this->value == nullptr) {
        this->value = payment;
    } else if (this->next == nullptr) {
        this->next = gcnew List_Payment(this->value);
        this->value = payment;
    } else {
        List_Payment^ tempo = gcnew List_Payment(this->next, this->value);
        this->value = payment;
        this->next = tempo;
    }
}

void List_Payment::setLast(Payment^ payment) {

    List_Payment^ last = getLastList();
    if (last->value == nullptr) {
        this->value = payment;
        return;
    }
    List_Payment^ tempo = gcnew List_Payment(payment);
    last->next = tempo;
}

void List_Payment::set(Payment^ payment, int i) {
    if (i == 0) {
        this->setFirst(payment);
    } if (i >= this->getSize()) {
        this->setLast(payment);
    } else {
        List_Payment^ get = getList(i - 1);
        List_Payment^ tempo = gcnew List_Payment(get->next, payment);
        get->next = tempo;
    }
}

Payment^ List_Payment::getFirst() {
    return this->value;
}

Payment^ List_Payment::getLast() {
    return this->getLastList()->value;
}

Payment^ List_Payment::get(int i) {
    return this->getList(i)->value;
}

List_Payment^ List_Payment::getLastList() {
    List_Payment^ tempo = this;
    while (tempo->next != nullptr) {
        tempo = tempo->next;
    }
    return tempo;
}

List_Payment^ List_Payment::getList(int i) {
    if (i == 0) {
        return this;
    }
    int j = 0;
    List_Payment^ tempo = this;
    while (tempo != nullptr && j < i) {
        tempo = tempo->next;
        j = j + 1;
    }
    return tempo;
}

int List_Payment::getSize() {
    int i = 0;
    if (this->value != nullptr) {
        i = 1;
    }
    List_Payment^ tempo = this;
    while (tempo->next != nullptr) {
        tempo = tempo->next;
        i = i + 1;
    }
    return i;
}