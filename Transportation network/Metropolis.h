

#ifndef METROPOLIS_H_
#define METROPOLIS_H_
#include "Network.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include "Map.h"

using namespace std;

class Metropolis {

private:

	int size;
	double **graph;
	Network network;
	Map<string,int> *map;


public:

	Metropolis();
	Metropolis(double **graph,const int &size,const char *arg1 = 0,const char *arg2 = 0,const int &arc = 0);
	Metropolis(const Metropolis &metro); //copy c'tor
	int getSize()const;
	double getGraph(const int &i,const int &j)const;
	void printTheMetropolinState()const; //print the updated metropolis state graph
	Network& getNetwork();
	void updateRoads();
	void updateAirInfectionInTheGraph(); //update the air infection of the specific road at the graph
	void getWorldFromTheUser(const char *arg1,const int &arc); //Receive the graph
	void getCarsFromTheUser(const char *arg2); //Receive the cars
	void allocateGraph(const int &size);
	Metropolis& operator=(Metropolis &met); //copy set operator
	Map<string,int>* getMap();
	void error();
	void updateGraph(const int &i,const int &j,const double &val);
	virtual ~Metropolis();
};

#endif /* METROPOLIS_H_ */
