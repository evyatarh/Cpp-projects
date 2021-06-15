
#ifndef SIMULATOR_H_
#define SIMULATOR_H_


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "Tackle.h"
#include "Cornerback.h"
#include "Linebacker.h"

using namespace std;

class Simulator {

private:

	vector <DefensivePacket*> originalDefensivePacket;
	vector <DefensivePacket*> updatedDefensivePacket;
	vector <vector<bool>> attackVec;
	int generationBeat;
	int stringsDimension;

	static const int MINPOPULATION = 2;
	static const int MAXPOPULATION = 1000;
	static const int MINSTRINGSDIMENSION = 3;
	static const int MAXSTRINGSDIMENSION = 10000;
	static const int MAXGENERATION = 1000000;

public:

	Simulator(const char *arg1,const char *arg2,const int &arc);
	Simulator(const Simulator &sim); //copy c'tor
	Simulator& operator=(const Simulator &sim); //copy set operator
	void startTheSimulator();
	int powerOfDefense();
	void flipBitInPropebuility();
	void printTheUpdatedPacket();
	void checkTheRc();
	void printType(const DefensivePacket *a);
	void printTheOriginalPacket();
	void getConfigFromTheUser(const char* arg1);
	void getOffenseFromTheUser(const char *arg2);
	void switchStrings(DefensivePacket * a,DefensivePacket * b);
	virtual ~Simulator();


	/********************  class InputErrorException  **************************/
	//this class represent an exception from kind of Input Error exception
	class InputErrorException{

	private:
		string str;
	public:
		//use default copy c'tor and copy set operator
		InputErrorException(const string &s):str(s){};
		virtual void printError()const{
			cerr << "ERROR: "<< str << endl;
		}
		virtual~InputErrorException(){}


	};


	/********************  class ArcException **************************/
	//this class represent an exception from kind of number of arguments exception
	class ArcException{

	private:
		string str;
	public:
		//use default copy c'tor and copy set operator
		ArcException(const string &s):str(s){};
		virtual void printError()const{
			cerr << "ERROR: "<< str  << "The number of the arguments does not fit" << endl;
		}
		virtual~ArcException(){}


	};






	/********************  class IOException **************************/
	//this class represent an exception from kind of Input Output exception
	class IOException{

	private:
		string str;
	public:
		//use default copy c'tor and copy set operator
		IOException(){}
		IOException(const string &s):str(s){};
		virtual void printError()const{
			cerr << "ERROR: "<< str <<" does not exist or cannot be processed" << endl;
		}
		virtual~IOException(){}


	};
};

#endif /* SIMULATOR_H_ */
