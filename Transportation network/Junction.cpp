

#include "Junction.h"
#include "Maseraty.h"
#include "FamilyCar.h"
/******************** c'tor method **************************/
Junction::Junction():NumOfCars(0),numOfRoads(0) {

	roadOptionsToDrive = 0;

}

/******************** copy c'tor method **************************/
Junction::Junction(const Junction &junction)
:NumOfCars(junction.NumOfCars),numOfRoads(junction.numOfRoads),serialNumberOfTheJunction(junction.serialNumberOfTheJunction){

	roadOptionsToDrive = new Road[numOfRoads];

	for(int i=0;i<numOfRoads;i++)
		roadOptionsToDrive[i]=junction.roadOptionsToDrive[i];
}

/******************** getSerialNumberOfTheJunction method **************************/
Position Junction::getSerialNumberOfTheJunction()const{return serialNumberOfTheJunction;}

/******************** getNumOfCars method **************************/
int Junction::getNumOfCars()const{return NumOfCars;}

/******************** getRoad method **************************/
Road& Junction::getRoad(const int &i){return roadOptionsToDrive[i];}

/******************** setSerialNumberOfTheJunction method **************************/
void Junction::setSerialNumberOfTheJunction(Position pos){ serialNumberOfTheJunction = pos;}

/******************** incNumOfCars method **************************/
void Junction::incNumOfCars(){++NumOfCars;}

/******************** decNumOfCars method **************************/
void Junction::decNumOfCars(){--NumOfCars;}

/******************** getNumOfRoads method **************************/
int Junction::getNumOfRoads()const{return numOfRoads;}

/******************** incNumOfRoads method **************************/
void Junction::incNumOfRoads(){++numOfRoads;}

/******************** allocateRoad method **************************/
void Junction::allocateRoad(){
	if(!numOfRoads) return;
	roadOptionsToDrive = new Road[numOfRoads];
}


/******************** operator= method **************************/
Junction& Junction::operator=(Junction &junc){


	this->NumOfCars = junc.NumOfCars;
	this->numOfRoads = junc.numOfRoads;
	this->serialNumberOfTheJunction = junc.serialNumberOfTheJunction;

	for (int i = 0; i < numOfRoads; i++)
		this->roadOptionsToDrive[i] = junc.roadOptionsToDrive[i];

	return *this;
}


/******************** setRoad method **************************/
void Junction::setRoad(Road &road,const int &i){
	roadOptionsToDrive[i]=road;
}

/******************** d'tor method **************************/
Junction::~Junction() {

 delete[] roadOptionsToDrive;
}

