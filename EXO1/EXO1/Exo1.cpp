#include <iostream>
class Exo {
private:
    int nb1, nb2;
public:
    
    Exo();
    Exo(int, int);

    
    int getnb1();
    void setnb1(int);
    int getnb2();
    void setnb2(int);

    //méthode addition
    void add();
};

Exo::Exo() {
    nb1 = 0;
    nb2 = 0;
}
Exo::Exo(int a, int b) {
    nb1 = a;
    nb2 = b;
}
int Exo::getnb1() {
    return nb1;
}
void Exo::setnb1(int a) {
    nb1 = a;
}
int Exo::getnb2() {
    return nb2;
}
void Exo::setnb2(int a) {
    nb2 = a;
}

//méthode addition
void Exo::add() {
    std::cout << nb1 + nb2 << std::endl;
}

int main() {
    Exo statique = Exo();
    Exo* dynamique = new Exo(0, 0);

    dynamique->setnb1(10);
    dynamique->setnb2(5);
    dynamique->add();

    delete dynamique;


    return 0;
}