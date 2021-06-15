

#include "Network.h"

/******************** c'tor method **************************/
Network::Network():numOfJunctions(0),actucalCars(0) {

	junctions = 0;
}

/******************** copy c'tor method **************************/
Network::Network(const Network &network)
:numOfJunctions(network.numOfJunctions),junctions(network.junctions),actucalCars(network.actucalCars){
}

/******************** c'tor method **************************/
Network::Network(const int &numOfJunctions)
:numOfJunctions(numOfJunctions),actucalCars(0){
	junctions = new Junction[numOfJunctions];
}

/******************** allocateJunctions method **************************/
void Network::allocateJunctions(){
	if(!numOfJunctions) return;
	junctions = new Junction[numOfJunctions];
}

/******************** setNumOfJunctions method **************************/
void Network::setNumOfJunctions(const int &numOfjunction){numOfJunctions = numOfjunction;}


/******************** getMaxCars method **************************/
int Network::getMaxCars()const{ return MAXCARS;}

/******************** nextBeatTime method **************************/
void Network::nextBeatTime(Map<string,int> *map){
	//this method doing the simulation
	srand(time(NULL));
	int temp,randomlyNeighbor,whereToGo;

	for(int i = 0;i<numOfJunctions;i++){

		if(!(junctions[i].getNumOfRoads()))continue; // if there are no roads from this junction

		for (int j = 0; j < actucalCars; j++) {

			if(cars[j]->getCurrentJunction()==i){

				if(cars[j]->getMovedAlready())continue;

				temp = (junctions[i].getNumOfRoads()) + 1;
				//the plus one is for the randomly numbers because 0 represent the same junction

				randomlyNeighbor = (rand()% temp); // numbers between 0 to number of roads


				if(typeid(*cars[j]) == typeid(LuxuryCar)){

					int stayOrLeave = (rand()% 2); //check if stay or leave this is 50%
					if(!stayOrLeave) continue; //if is 1 so he need to leave the junction

				}

				if(typeid(*cars[j]) == typeid(FamilyCar)){

					if(!randomlyNeighbor) continue; //if is the same junction - stay
					--randomlyNeighbor; //to get the specific road from the array


				}

				whereToGo = junctions[i].getRoad(randomlyNeighbor).getDestination().getX();
				updateAirInfection(junctions[i],randomlyNeighbor,j);

				*(map->get(cars[j]->getSerialNumber())) = whereToGo;

				cars[j]->setCurrentJunction(whereToGo); // moving cars from junction to junction
				cars[j]->setMovedAlready(true);


			}
		}

	}

	resetMovedAlready();

}


/******************** getActualCars method **************************/
int Network::getActualCars()const{return actucalCars;}


/******************** setActualCars method **************************/
void Network::setActualCars(const int &num){ actucalCars = num;}


/******************** getCar method **************************/
Car* Network::getCar(const int &i){ return cars[i];}


/******************** setCar method **************************/
void Network::setCar(Car* car,const int &i){ cars[i] = car;}

/******************** updateAirInfection method **************************/
void Network::updateAirInfection(Junction &junc,const int &loc,const int &index){

	double a = (cars[index]->getInfectionNumerator());
	double sum = (junc.getRoad(loc).getDistance());

	junc.getRoad(loc).AddAirInfection(a/sum);

}

/******************** resetMovedAlready method **************************/
void Network::resetMovedAlready(){

	for(int i=0;i<actucalCars;i++) cars[i]->setMovedAlready(false);
}

/******************** printTheCarsState method **************************/
void Network::printTheCarsState(){

	for(int i=0;i<numOfJunctions;i++){
		cout << i+1 << ":";
		for(int j=0;j<actucalCars;j++){
			if(cars[j]->getCurrentJunction() == i)cout <<" " << cars[j]->getSerialNumber();


		}

		cout << endl;
	}
}
/******************** operator= method **************************/
Network& Network::operator=(Network &net){

	int temp = numOfJunctions;

	this->numOfJunctions = net.numOfJunctions;

	if(temp < net.numOfJunctions) allocateJunctions();

	for (int i = 0; i < numOfJunctions; ++i)
		this->junctions[i] = net.junctions[i];

	return *this;
}

/******************** getJunction method **************************/
Junction& Network::getJunction(const int &i) {return junctions[i];}

/******************** setJunction method **************************/
void Network::setJunction(Junction &newJunction,const int &i){junctions[i] = newJunction;}

/********************d'tor method **************************/
Network::~Network() {
	for(int i=0;i<actucalCars;i++) delete cars[i];
	delete []junctions;

}

