

#include "Cornerback.h"

/******************** c'tor method **************************/
Cornerback::Cornerback():DefensivePacket() {}

/******************** c'tor method **************************/
Cornerback::Cornerback(const int n,const int si):DefensivePacket(n,si){}

/******************** copy c'tor method **************************/
Cornerback::Cornerback(const Cornerback& cor):DefensivePacket(cor){}

/******************** operator= method **************************/
Cornerback& Cornerback::operator=(const Cornerback& cor){
	this->DefensivePacket::operator =(cor);
	return *this;
}

/******************** setPropability method **************************/
void Cornerback::setPropability(double prop){setPropability(prop);}

/******************** d'tor method **************************/
Cornerback::~Cornerback() {}

