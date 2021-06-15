

#ifndef LUXURYCAR_H_
#define LUXURYCAR_H_
#include "Car.h"
class LuxuryCar: public virtual Car {

	//for this class i used the defaults of the The Big Three(Car class)
public:

	LuxuryCar():Car("",3) {}//calling Car c'tor with empty serial number and the infection numerator

	virtual ~LuxuryCar(){}
};

#endif /* LUXURYCAR_H_ */
