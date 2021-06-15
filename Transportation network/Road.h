

#ifndef ROAD_H_
#define ROAD_H_
#include "Position.h"
#include <iostream>

using namespace std;

class Road {

private:

	Position destination; //this variable represent the destination of the road aka junction
	double airInfection; //this variable represent the air infection at the moment on the road
	double distance; //the weight of the road

public:

	Road();
	Road(const Road &road); //copy c'tor
	Road(const double &dis,const Position &destination);
	double getAirInfection()const;
	double getDistance()const;
	Position getDestination()const;
	void setDestination(Position option);
	void setFrom(const int &froms);
	Road& operator=(Road &r); //copy set operator
	Road& operator+(const double &d);
	void setDistance(const double &dis);
	void AddAirInfection(const double &dis);
	virtual ~Road();
};

#endif /* ROAD_H_ */
