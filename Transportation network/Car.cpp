
#include "Car.h"

/******************** c'tor method **************************/
Car::Car():serialNumber(0),infectionNumerator(0),movedAlready(false),currentJunction(0){}

/******************** c'tor method **************************/
Car::Car(const string &serial,const int &infe):serialNumber(serial),
		infectionNumerator(infe),movedAlready(false),currentJunction(0){}

/******************** copy c'tor method **************************/
Car::Car(const Car &car):serialNumber(car.serialNumber),
		infectionNumerator(car.infectionNumerator),movedAlready(car.movedAlready),currentJunction(car.currentJunction){}

/******************** getSerialNumber method **************************/
string Car::getSerialNumber()const{ return serialNumber; }

/******************** getInfectionNumerator method **************************/
int Car::getInfectionNumerator()const{ return infectionNumerator; }

/******************** getCurrentJunction method **************************/
int Car::getCurrentJunction(){ return currentJunction; }

/******************** setCurrentJunction method **************************/
void Car::setCurrentJunction(const int &pos){ currentJunction = pos;}

/******************** operator= method **************************/
Car& Car::operator=(Car &r){

	this->serialNumber = r.serialNumber;
	this->infectionNumerator = r.infectionNumerator;
	this->movedAlready = r.movedAlready;
	this->currentJunction = r.currentJunction;
	return *this;
}

/******************** operator= method **************************/
Car& Car::operator=(int x){

	this->serialNumber = x;
	return *this;
}


/******************** setSerialNumber method **************************/
void Car::setSerialNumber(const string &serial){ serialNumber = serial;}


/******************** setInfectionNumerator method **************************/
void Car::setInfectionNumerator(const int &infe){ infectionNumerator = infe;}

/******************** setMovedAlready method **************************/
void Car::setMovedAlready(const bool &bo){movedAlready = bo;}

/******************** getMovedAlready method **************************/
bool Car::getMovedAlready()const{return movedAlready;}

/******************** d'tor method **************************/
Car::~Car() {}

