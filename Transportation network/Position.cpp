

#include "Position.h"

/******************** c'tor method **************************/
Position::Position():x(0){}

/******************** c'tor method **************************/
Position::Position(const int &i):x(i){}

/******************** copy c'tor method **************************/
Position::Position(const Position &pos):x(pos.x){}

/******************** getX method **************************/
int Position::getX()const{ return x;}


/******************** equal method **************************/
bool Position::equal(const Position &a)const{

		if((this->x==a.getX()))return true;
		return false;
}

/******************** operator= method **************************/
Position& Position::operator=(Position &pos){
	this->x = pos.x;
	return *this;
}

/******************** equal method **************************/
bool Position::equal(const int &a)const{

	if((this->x==a))return true;
	return false;
}

/******************** setX method **************************/
void Position::setX(const char &i){ x=i;}


/******************** d'tor method **************************/
Position::~Position() {}

