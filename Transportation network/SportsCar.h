
#ifndef SPORTSCAR_H_
#define SPORTSCAR_H_
#include "Car.h"

class SportsCar: public virtual Car {

	//for this class i used the defaults of the The Big Threes(Car class)
public:
	SportsCar():Car("",4) {}//calling Car c'tor with empty serial number and the infection numerator

	virtual ~SportsCar(){}
};

#endif /* SPORTSCAR_H_ */
