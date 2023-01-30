/*#include "iostream"

using namespace std;

class A
{
public:
    virtual void afficher();
};

class B : public A
{
public:
    void afficher();
};

void A::afficher()
{
    cout << "je suis A" << endl;
}

void B::afficher()
{
    cout << "je suis B" << endl;
}

int main()
{
    A* o1;
    o1 = new A();
    B* o2;
    o2 = new B();

    o1->afficher();
    o2->afficher();
    o1 = o2;
    o1->afficher();
}*/