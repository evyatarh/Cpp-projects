

#ifndef SIMULATOR_H_
#define SIMULATOR_H_
#include "Metropolis.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Simulator {

private:

	double **graph;
	Metropolis metropolis;
	static const int MAXTIMEBEAT = 1000000;

public:

	Simulator(const char *arg1,const char *arg2,const int &arc);
	Simulator(const Simulator &sim); //copy c'tor
	void startTheSimulator();
	Simulator& operator=(Simulator &sim); //copy set operator
	virtual ~Simulator();
};

#endif /* SIMULATOR_H_ */
