#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"

using namespace std;

void afficherObject(A* o) {
    o->afficher();
}

int main()
{
    cout << "Hello World!\n";
    C* c = new C();
    B* b = new B();
    afficherObject(b);
    afficherObject(c);
}
