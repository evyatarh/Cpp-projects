/*
 * Warehouse.h
 * This class represents Warehouse object
 * Created on: May 13, 2019
 * Author: Evya
 */

#ifndef WAREHOUSE_H_
#define WAREHOUSE_H_

#include <iostream>
#include "Date.h"

using namespace std;

class Warehouse {

private:

	string name;
	Date arrivDate,depaDate;
	int numOfBoxes;

public:

	Warehouse();
	Warehouse(const string &name,Date arriv,Date depa,int boxes);
	Warehouse(const Warehouse &wr);
	Warehouse& operator=(const Warehouse &wr);
	Warehouse(Warehouse &&wr);
	Warehouse& operator=(Warehouse &&wr);

	const Date& getArrivel();
	const Date& getdepa();
	const string& getName()const;
	void setNumOfBoxes(int num);
	int getNumOfBoxes()const;

	virtual ~Warehouse();
};

#endif /* WAREHOUSE_H_ */
