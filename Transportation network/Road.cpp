

#include "Road.h"


/******************** c'tor method **************************/
Road::Road():airInfection(0),distance(0) {}

/******************** copy c'tor method **************************/
Road::Road(const Road &road)
:destination(road.destination),airInfection(road.airInfection),distance(road.distance) {
}

/******************** c'tor method **************************/
Road::Road(const double &dis,const Position &des)
:destination(des) ,airInfection(0),distance(dis){
}

/******************** getAirInfection method **************************/
double Road::getAirInfection()const{return airInfection;}

/******************** getDistance method **************************/
double Road::getDistance()const{return distance;}

/******************** getDestination method **************************/
Position Road::getDestination()const{return destination;}

/******************** setDistance method **************************/
void Road::setDistance(const double &dis){distance = dis;}

/******************** setDestination method **************************/
void Road::setDestination(Position des){ destination = des;}

/******************** operator+ method **************************/
Road& Road::operator+(const double &d){

	this->airInfection = this->airInfection + d;
	return *this;
}


/******************** operator= method **************************/
Road& Road::operator=(Road &r){

	this->destination = r.destination;
	this->airInfection = r.airInfection;
	this->distance = r.distance;


	return *this;
}

/******************** AddAirInfection method **************************/
void Road::AddAirInfection(const double &dis){ airInfection += dis;}


/******************** d'tor method **************************/
Road::~Road() {}

