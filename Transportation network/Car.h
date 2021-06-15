

#ifndef CAR_H_
#define CAR_H_
#include <iostream>


using namespace std;

class Car {

private:

	string serialNumber;
	int infectionNumerator; //this variable represent the infection numerator of the car
	bool movedAlready; //this variable check if the car already moved to the current junction
	int currentJunction;

public:

	Car();
	Car(const string &serial,const int &infe);
	Car(const Car &car); //copy c'tor
	string getSerialNumber()const;
	int getInfectionNumerator()const;
	bool getMovedAlready()const;
	int getCurrentJunction();
	void setMovedAlready(const bool &bo);
	void setCurrentJunction(const int &pos);
	void setSerialNumber(const string &serial);
	void setInfectionNumerator(const int &infe);
	Car& operator=(Car &r); //copy set operator
	Car& operator=(int x);
	virtual ~Car() = 0;
};

#endif /* CAR_H_ */
