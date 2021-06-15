

#include "Metropolis.h"

/******************** c'tor method **************************/
Metropolis::Metropolis(double **graph,const int &size,const char *arg1,const char *arg2,const int &arc)
:size(size),network(),map(new Map<string,int>(network.getMaxCars())){


	getWorldFromTheUser(arg1,arc);
	getCarsFromTheUser(arg2);


}

/******************** copy c'tor method **************************/
Metropolis::Metropolis(const Metropolis &metro)
:size(metro.size),network(metro.network){

	allocateGraph(metro.size);

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			this->graph[i][j] = graph[i][j];
		}
	}
}


/******************** getSize method **************************/
int Metropolis::getSize()const{return size;}


/******************** getGraph method **************************/
double Metropolis::getGraph(const int &i,const int &j)const{return graph[i][j];}

/******************** getNetwork method **************************/
Network& Metropolis::getNetwork(){return network;}

/******************** updateGraph method **************************/
void Metropolis::updateGraph(const int &i,const int &j,const double &val){graph[i][j] = val;}

/******************** allocateGraph method **************************/
void Metropolis::allocateGraph(const int &size){
	if(!size) return;
	graph = new double*[size];
	for(int i=0;i<size;i++) graph[i] = new double[size];
}

/******************** updateAirInfectionInTheGraph method **************************/
void Metropolis::updateAirInfectionInTheGraph(){
	//this method update the air infection in the graph - meaning that the road who drove by a car from
	//junction to junction will be update by the air infection unit, so the cell in the graph will be update
	//in the specific cell who changed if the air infection does not changed and stay in the started value (0)
	//so the distance between the junctions will still showed on the graph

	for(int i=0;i<size;i++){
		for(int j=0;j<network.getJunction(i).getNumOfRoads();j++)
				graph[i][network.getJunction(i).getRoad(j).getDestination().getX()] = network.getJunction(i).getRoad(j).getAirInfection();

	}
}

/******************** getCarsFromTheUser method **************************/
void Metropolis::getCarsFromTheUser(const char *arg2){

	char ch;
	int c,k = 0;

	ifstream secondFile(arg2); //open the file. if does not success will throw an error
	if (!secondFile) error();

	for(int i=0;i<size;i++){

		secondFile.get(ch); // get the number of the junction


		if(isdigit(ch)){

			network.getJunction(i).setSerialNumberOfTheJunction(Position(i));


			while((c=secondFile.get())!= '\n'){

				if(secondFile.eof())break;

				if(isalpha(c) && isupper(c)){

					switch(c){

					case 'L': network.setCar(new LuxuryCar(),k); break;
					case 'S': network.setCar(new SportsCar(),k) ; break;
					case 'M': network.setCar(new Maseraty(),k); break;
					case 'F': network.setCar(new FamilyCar(),k); break;
					default:;
					}

					string s;
					s = c;
					c=secondFile.get();

					if(isdigit(c)){

						if(isdigit(secondFile.peek())){

							while(isdigit(secondFile.peek())){
								//keep doing that to get the number. if for example is 100
								s.push_back(c);
								c=secondFile.get();

							}
						}
						 s.push_back(c);

						map->put(s,i);

						network.getCar(k)->setCurrentJunction(i);
						network.getCar(k++)->setSerialNumber(s);

						network.getJunction(i).incNumOfCars();

					}
				}

			}

		}

		else error(); //if the first char does not represent a number of junction
	}
	network.setActualCars(k);
	secondFile.close();

}

/******************** getWorldFromTheUser method **************************/
void Metropolis::getWorldFromTheUser(const char *arg1,const int &arc){

	//this method get the graph from the file into the metropolis world

	int i=0,j=0;

	if (arc != 3) error();

	ifstream firstFile(arg1);

	if(!firstFile) error();

	string s;
	getline(firstFile,s);

	size = s[0] - '0';
	if(!size) error();
	allocateGraph(size);

	network.setNumOfJunctions(size);
	network.allocateJunctions();

	double num = 0.0;
	while(firstFile>>num){

		if(j==size){
			j=0;
			i++;
		}

		if(i==size)break;

		graph[i][j] = num;

		if(graph[i][j])
			network.getJunction(i).incNumOfRoads();
		j++;

	}


	updateRoads();
	firstFile.close();

}

/******************** error method **************************/
void Metropolis::error() {
	cerr << "ERROR: Invalid input.";
	exit(-1);
}

/******************** updateRoads method **************************/
void Metropolis::updateRoads(){

	int k = 0;

	for(int i=0;i<size;i++){

		network.getJunction(i).allocateRoad();
		k=0;
		for(int j=0;j<size;j++){

			if(graph[i][j]){

				Road road;
				road.setDistance(graph[i][j]);
				road.setDestination(Position(j)); //the number of the junction this road lead to
				network.getJunction(i).setRoad(road,k++);


			}
		}

	}
}


/******************** operator= method **************************/
Metropolis& Metropolis::operator=(Metropolis &met){

	this->network = met.network;

	if(size < met.size) allocateGraph(met.size);
	this->size = met.size;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			this->graph[i][j] = met.graph[i][j];
		}
	}
	return *this;
}


/******************** getMap method **************************/
Map<string,int>* Metropolis::getMap(){return map;}

/******************** printTheMetropolinState method **************************/
void Metropolis::printTheMetropolinState()const{

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout << setprecision(3) << graph[i][j] ;
			if(j!=size-1) cout << " ";
		}
		cout << endl;
	}
}

/******************** d'tor method **************************/
Metropolis::~Metropolis() {
	for(int i=0;i<size;i++) delete[] graph[i];
	delete[] graph;
	 map->deleteAll();
}




