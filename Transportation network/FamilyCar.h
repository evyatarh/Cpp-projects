

#ifndef FAMILYCAR_H_
#define FAMILYCAR_H_
#include "Car.h"

class FamilyCar: public virtual Car {

	//for this class i used the defaults of the The Big Three(Car class)
public:

	FamilyCar():Car("",2) {} //calling Car c'tor with empty serial number and the infection numerator

	virtual ~FamilyCar(){}
};

#endif /* FAMILYCAR_H_ */
