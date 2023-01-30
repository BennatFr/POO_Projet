#include <iostream>
#include "CLa.h"

using namespace std;

int main() {
    cout << "EI Nathan Ferrer CPI A2" << endl;
    //Init object
    CLa o1 = CLa();
    CLa* o2 = new CLa(1,2);

    //set value object
    o1.setNb1(3);
    o1.setNb2(4);

    //Show result of methode add()
    cout << "o1 : " << o1.getNb1() << " + " << o1.getNb2() << " = " << o1.add() << endl;
    cout << "o2 : " << o2->getNb1() << " + " << o2->getNb2() << " = " << o2->add() << endl;

    //delete object
    delete o2;
}
