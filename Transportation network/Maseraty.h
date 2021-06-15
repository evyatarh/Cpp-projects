

#ifndef MASERATY_H_
#define MASERATY_H_

#include "LuxuryCar.h"
#include "SportsCar.h"

class Maseraty:   public LuxuryCar, public SportsCar {

	//for this class i used the defaults of the The Big Threes(Car class)
public:

	Maseraty():Car("",3){} //calling Car c'tor with empty serial number and the infection numerator

	virtual ~Maseraty(){}
};

#endif /* MASERATY_H_ */
