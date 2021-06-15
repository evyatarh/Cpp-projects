

#include "Simulator.h"


/******************** c'tor method **************************/
Simulator::Simulator(const char *arg1,const char *arg2,const int &arc)
:metropolis(graph,0,arg1,arg2,arc) {
}

/******************** copy c'tor method **************************/
Simulator::Simulator(const Simulator &sim):metropolis(sim.metropolis){
	this->graph = sim.graph;
}

/******************** startTheSimulator method **************************/
void Simulator::startTheSimulator(){
//this method running the business of the Oranjestad

	int timeBeat;

	cin >> timeBeat;

	if(timeBeat > MAXTIMEBEAT) metropolis.error();

	while(timeBeat--)
		metropolis.getNetwork().nextBeatTime(metropolis.getMap());


	metropolis.updateAirInfectionInTheGraph();
	metropolis.printTheMetropolinState();
	metropolis.getNetwork().printTheCarsState();

}


/******************** operator= method **************************/
Simulator& Simulator::operator=(Simulator &sim){

	this->metropolis = sim.metropolis;
	this->graph = sim.graph;

	return *this;

}


/******************** d'tor method **************************/
Simulator::~Simulator() {}


