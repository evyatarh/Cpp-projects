/*
 * Warehouse.cpp
 *
 * Created on: May 13, 2019
 * Author: Evya
 */

#include "Warehouse.h"

/******************** default c'tor method **************************/
Warehouse::Warehouse():name(""),arrivDate(Date()),depaDate(Date()),numOfBoxes(0) {}


/******************** c'tor method **************************/
Warehouse::Warehouse(const string &name,Date arriv,Date depa,int boxes):name(name),
		arrivDate(arriv),depaDate(depa),numOfBoxes(boxes){}


/******************** copy c'tor method **************************/
Warehouse::Warehouse(const Warehouse &wr):name(wr.name),arrivDate(wr.arrivDate),
		depaDate(wr.depaDate),numOfBoxes(wr.numOfBoxes){

}


/******************** copy set method **************************/
Warehouse& Warehouse::operator=(const Warehouse &wr){
	if(this!=&wr){
		this->arrivDate = wr.arrivDate;
		this->depaDate = wr.depaDate;
		this->name = wr.name;
		this->numOfBoxes = wr.numOfBoxes;
	}
	return *this;

}


/******************** move c'tor method **************************/
Warehouse::Warehouse(Warehouse &&wr){

	this->arrivDate = move(wr.arrivDate);
	this->depaDate = move(wr.depaDate);
	this->name = wr.name;
	wr.name.clear();
	this->numOfBoxes = wr.numOfBoxes;
	wr.numOfBoxes = 0;

}
/******************** move set method **************************/
Warehouse& Warehouse::operator=(Warehouse &&wr){

	if(this != &wr){
		this->arrivDate = move(wr.arrivDate);
		this->depaDate = move(wr.depaDate);
		this->name = wr.name;
		wr.name.clear();
		this->numOfBoxes = wr.numOfBoxes;
		wr.numOfBoxes = 0;
	}
	return *this;
}


/******************** setNumOfBoxes method **************************/
void Warehouse::setNumOfBoxes(int num){numOfBoxes = num;}


/******************** getName method **************************/
const string& Warehouse::getName()const{return name;}


/******************** getNumOfBoxes method **************************/
int Warehouse::getNumOfBoxes()const{return numOfBoxes;}


/******************** getArrivel method **************************/
const Date& Warehouse::getArrivel(){return arrivDate;}


/******************** getdepa method **************************/
const Date& Warehouse::getdepa(){return depaDate;}


/******************** d'tor method **************************/
Warehouse::~Warehouse() {}

