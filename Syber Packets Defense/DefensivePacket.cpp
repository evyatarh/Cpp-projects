
#include "DefensivePacket.h"

/******************** c'tor method **************************/
DefensivePacket::DefensivePacket():size(0),father(0),propability(0),adjustmentStrength(0){}

/******************** c'tor method **************************/
DefensivePacket::DefensivePacket(const double prop,const int size):size(size),father(0),propability(prop),adjustmentStrength(0){}

/******************** copy c'tor method **************************/
DefensivePacket::DefensivePacket(const DefensivePacket& dp):size(dp.size),father(dp.father),
		propability(dp.propability),adjustmentStrength(dp.adjustmentStrength){}

/******************** operator= method **************************/
DefensivePacket& DefensivePacket::operator=(const DefensivePacket& dp){

	if(this!=&dp){

		this->size = dp.size;
		this->adjustmentStrength = dp.adjustmentStrength;
		this->propability = dp.propability;
		this->defVec = dp.defVec;
		this->father = dp.father;

	}
	return *this;
}

/******************** getFather method **************************/
int DefensivePacket::getFather()const{return father;}

/******************** setFather method **************************/
void DefensivePacket::setFather(int f){father = f;}

/******************** setDefenseSize method **************************/
void DefensivePacket::setDefenseSize(int siz){size = siz;}

/******************** setAdjusment method **************************/
void DefensivePacket::setAdjusment(int adj){adjustmentStrength = adj;}

/******************** getVec method **************************/
vector<bool> & DefensivePacket::getVec(){return defVec;}

/******************** getAdjusment method **************************/
int DefensivePacket::getAdjusment(){return adjustmentStrength;}

/******************** getPropability method **************************/
double DefensivePacket::getPropability(){return propability;}

/******************** pushRandValuesToVec method **************************/
void DefensivePacket::pushRandValuesToVec(){

	for (int i = 0; i < size; i++)
		defVec.push_back((rand()% 2));

}

/******************** d'tor method **************************/
DefensivePacket::~DefensivePacket(){}

