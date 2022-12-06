#include "List_Item.h"

List_Item::List_Item() {

    this->next = nullptr;
    this->value = nullptr;
}

List_Item::List_Item(Item^ item) {

    this->next = nullptr;
    this->value = item;
}

List_Item::List_Item(List_Item^ listItem, Item^ item) {

    this->next = listItem;
    this->value = item;
}

List_Item::~List_Item() {
    delete next;
    delete value;
}

void List_Item::setFirst(Item^ item)
{
    if (this->value == nullptr) {
        this->value = item;
    } else if (this->next == nullptr) {
        this->next = gcnew List_Item(this->value);
        this->value = item;
    } else {
        List_Item^ tempo = gcnew List_Item(this->next, this->value);
        this->value = item;
        this->next = tempo;
    }
}

void List_Item::setLast(Item^ item) {

    List_Item^ last = getLastList();
    if (last->value == nullptr) {
        this->value = item;
        return;
    }
    List_Item^ tempo = gcnew List_Item(item);
    last->next = tempo;
}

void List_Item::set(Item^ item, int i) {
    if (i == 0) {
        this->setFirst(item);
    } if (i >= this->getSize()) {
        this->setLast(item);
    } else {
        List_Item^ get = getList(i - 1);
        List_Item^ tempo = gcnew List_Item(get->next, item);
        get->next = tempo;
    }
}

void List_Item::del(int i) {
    if (i == 0) {
        this->delFirst();
    } if (i >= this->getSize()) {
        //this->delLast()
    }
}

void List_Item::delFirst() {
    if (this->next == nullptr || this->value) {
        this->value = nullptr;
    } else {
        List_Item^ nxt = this->next;
        this->next = nxt->next;
        this->value = nxt->value;
    }
}

Item^ List_Item::getFirst()
{
    return this->value;
}

Item^ List_Item::getLast() {
    return this->getLastList()->value;
}

Item^ List_Item::get(int i)
{
    return this->getList(i)->value;
}

List_Item^ List_Item::getLastList()
{
    List_Item^ tempo = this;
    while (tempo->next != nullptr) {
        tempo = tempo->next;
    }
    return tempo;
}

List_Item^ List_Item::getList(int i)
{
    if (i == 0) {
        return this;
    }
    int j = 0;
    List_Item^ tempo = this;
    while (tempo != nullptr && j < i) {
        tempo = tempo->next;
        j = j + 1;
    }
    return tempo;
}

int List_Item::getSize()
{
    int i = 0;
    if (this->value != nullptr) {
        i = 1;
    }
    List_Item^ tempo = this;
    while (tempo->next != nullptr) {
        tempo = tempo->next;
        i = i + 1;
    }
    return i;
}