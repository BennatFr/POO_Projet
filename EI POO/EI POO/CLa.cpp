#include "CLa.h"

CLa::CLa() {
	this->nb1 = 0;
	this->nb2 = 0;
}

CLa::CLa(int nb1, int nb2) {
	this->nb1 = nb1;
	this->nb2 = nb2;
}

int CLa::getNb1() {
	return nb1;
}

int CLa::getNb2() {
	return nb2;
}

void CLa::setNb1(int nb1) {
	this->nb1 = nb1;
}

void CLa::setNb2(int nb2) {
	this->nb2 = nb2;
}

int CLa::add() {
	return this->nb1 + this->nb2;
}
