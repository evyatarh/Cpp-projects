

#ifndef POSITION_H_
#define POSITION_H_
#include <iostream>

using namespace std;

class Position {

private:

	int x;

public:

	Position();
	Position(const int &i);
	Position(const Position &pos); //copy c'tor
	int getX()const;
	bool equal(const Position &a)const; //check if a Point is equal
	bool equal(const int &a)const;
	void setX(const char &i);
	Position& operator=(Position &pos); //copy set operator
	virtual ~Position();
};

#endif /* POSITION_H_ */
