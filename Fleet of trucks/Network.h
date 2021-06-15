/*
 * Network.h
 * This class represent Network object
 * Created on: May 13, 2019
 * Author: Evya
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

#include "Warehouse.h"
#include "Edge.h"
#include "Graph.h"

using namespace std;

class Network {

private:

	static const int MAX_WAREHOUSE_NAME_LENGTH = 16;
	Graph boxesGraph;
	Graph shippingTimeGraph;
	string output;

public:

	Network();
	Network(const Network &net);
	Network(const int &arc,char *files[]);
	Network& operator=(const Network &net);
	Network(Network &&net);
	Network& operator=(Network &&net);

	void run();
	void getNetworkFromUser(const char* filename);
	void checkWarehouseName(const string &name,const string &filename,int line);
	void loadData(const string &name);
	void outbound(const string &ware);
	void inbound(const string &ware);
	void inventory(const string &source,const string &date);
	void shortest(const string &source,const string &target);
	void print();
	void checkIfValid(const string &num_of_boxes,const string &filename,int line);
	bool checkIfSourceExist(shared_ptr<Warehouse>sourceVertex,vector<shared_ptr<Warehouse>> v)const;

	virtual ~Network();



	/********************  class InputErrorException  **************************/

	class InputErrorException{

	private:
		string str;
		int line;
	public:
		//use default copy c'tor and copy set operator
		InputErrorException(const string &s,int line):str(s),line(line){};
		virtual void printError()const{
			cerr << "‫‪Invalid‬‬ ‫‪input‬‬ ‫‪in‬‬ ‫‪file‬‬: "<< str  << "‫‪at‬‬ ‫‪line‬‬" << line << endl;
		}
		virtual~InputErrorException(){}


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


	class InvalidArguments{

	private:
		string str;
	public:
		//use default copy c'tor and copy set operator
		InvalidArguments(){}
		InvalidArguments(const string &s):str(s){};
		virtual void printError()const{
			cerr << str << endl;
		}
		virtual~InvalidArguments(){}


	};
};


#endif /* NETWORK_H_ */
