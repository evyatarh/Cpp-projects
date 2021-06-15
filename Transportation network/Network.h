

#ifndef NETWORK_H_
#define NETWORK_H_

#include "Junction.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Map.h"
#include "Maseraty.h"
#include "FamilyCar.h"
using namespace std;

class Network {

private:

	const static int MAXCARS = 10000;
	int numOfJunctions;
	Junction *junctions;
	Car* cars[MAXCARS]; //iv'e put the cars into a array of pointers to the specific type of car
	int actucalCars; //tell me how many actually cars are there

public:

	Network();
	Network(const Network &network); //copy c'tor
	Network(const int &numOfJunctions);
	void allocateJunctions();
	int getMaxCars()const;
	void setNumOfJunctions(const int &numOfjunction);
	Junction& getJunction(const int &i);
	void printTheCarsState(); //print the cars
	Network& operator=(Network &net); //copy set operator
	void setJunction(Junction &newJunction,const int &i);
	void updateAirInfection(Junction &junc,const int &loc,const int &index); //update air infection at the specific road
	void nextBeatTime(Map<string,int> *map); //do the simulation
	Car* getCar(const int &i);
	int getActualCars()const;
	void setCar(Car* car,const int &i);
	void resetMovedAlready(); //reset the variable moved already at the specific car that moved already to the junction
	void setActualCars(const int &num);
	virtual ~Network();
};

#endif /* NETWORK_H_ */
