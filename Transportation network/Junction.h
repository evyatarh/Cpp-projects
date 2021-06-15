

#ifndef JUNCTION_H_
#define JUNCTION_H_


#include "Road.h"
#include <typeinfo>

using namespace std;

class Junction {

private:

	int NumOfCars;
	int numOfRoads;
	Position serialNumberOfTheJunction;
	Road *roadOptionsToDrive; //the road options the car can drive on

public:

	Junction();
	Junction(const Junction &junction); //copy c'tor
	Position getSerialNumberOfTheJunction()const;
	int getNumOfCars()const;
	Road& getRoad(const int &i);
	void setSerialNumberOfTheJunction(Position pos);
	void incNumOfCars();
	Junction& operator=(Junction &junc); //copy set operator
	void decNumOfCars();
	int getNumOfRoads()const;
	void incNumOfRoads();
	void allocateRoad(); //allocate the array of the roads
	void setRoad(Road &road,const int &i);
	virtual ~Junction();
};

#endif /* JUNCTION_H_ */
