
#include "Tackle.h"

/******************** c'tor method **************************/
Tackle::Tackle():DefensivePacket() {}

/******************** c'tor method **************************/
Tackle::Tackle(const int n,const int si):DefensivePacket(n,si){}

/******************** copy c'tor method **************************/
Tackle::Tackle(const Tackle& cor):DefensivePacket(cor){}

/******************** operator= method **************************/
Tackle& Tackle::operator=(const Tackle& cor){
	this->DefensivePacket::operator =(cor);
	return *this;
}

/******************** setPropability method **************************/
void Tackle::setPropability(double prop){setPropability(prop);}

/******************** d'tor method **************************/
Tackle::~Tackle() {}

