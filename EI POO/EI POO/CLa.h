#pragma once
class CLa {
private:
	int nb1;
	int nb2;
public:
	//Constructor 
	CLa();
	CLa(int nb1, int nb2);
	//Getter
	int getNb1();
	int getNb2();
	//setter
	void setNb1(int nb1);
	void setNb2(int nb2);
	
	//other
	int add();
};

