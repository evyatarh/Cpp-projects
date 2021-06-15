

#include "Linebacker.h"

/******************** c'tor method **************************/
Linebacker::Linebacker():DefensivePacket() {}

/******************** c'tor method **************************/
Linebacker::Linebacker(const int n,const int si):DefensivePacket(n,si){}

/******************** copy c'tor method **************************/
Linebacker::Linebacker(const Linebacker& cor):DefensivePacket(cor){}

/******************** operator= method **************************/
Linebacker& Linebacker::operator=(const Linebacker& cor){
	this->DefensivePacket::operator =(cor);
	return *this;
}

/******************** setPropability method **************************/
void Linebacker::setPropability(double prop){setPropability(prop);}

/******************** d'tor method **************************/
Linebacker::~Linebacker() {}

