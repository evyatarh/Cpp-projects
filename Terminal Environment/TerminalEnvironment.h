
#ifndef TERMINALENVIRONMENT_H_
#define TERMINALENVIRONMENT_H_

#include <sstream>
#include <iostream>
#include <map>
#include <cstdio>
#include "FileBuiltIn.h"

using namespace std;


class TerminalEnvironment {

private:

	map<string,FileBuiltIn*> manager; //this map holds all the file in the terminal
	map<string,FileBuiltIn*>::iterator it; //to iterate over the map

public:

	TerminalEnvironment();
	TerminalEnvironment(const TerminalEnvironment &t); //copy c'tor
	TerminalEnvironment& operator=(const TerminalEnvironment &t); //copy set operator
	//terminal functionalities
	void touch(const string &name);
	void copy(const string &source,const string &target);
	void remove(const string &fileName);
	void move(const string &source,const string &target);
	void cat(const string &fileName);
	void head(const string &fileName,int n);
	void tail(const string &fileName,int n);
	void runTerminal(); //running all the terminal
	void checkIfTheFileExist(map<string,FileBuiltIn*>::iterator &it,const string &fileName);
	virtual ~TerminalEnvironment();



	/********************  class InvalidCommand **************************/
	//this class represent an exception from kind of invalid command
	class InvalidCommand{

	public:
		//use default copy c'tor and copy set operator
		InvalidCommand(){};
		virtual void printError()const{
			cerr << "ERROR: command is not supported" << endl;
		}
		virtual ~InvalidCommand(){}

	};


	/********************  class IOException **************************/
	//this class represent an exception from kind of Input Output exception
	class IOException{

	private:
		string str;
	public:
		//use default copy c'tor and copy set operator
		IOException(const string &s):str(s){};
		virtual void printError()const{
			cerr << "ERROR: "<< str <<" does not exist or cannot be processed" << endl;
		}
		virtual~IOException(){}


	};



	/********************  class InvalidUsageCommand **************************/
	//this class represent an exception from kind of invalid usage command
	class InvalidUsageCommand{

	private:
		string str;
	public:
		//use default copy c'tor and copy set operator
		InvalidUsageCommand(const string &s):str(s){}
		void printError()const{
			cerr << "ERROR: USAGE " << str  << endl ;
		}
		virtual ~InvalidUsageCommand(){}
	};


};

#endif /* TERMINALENVIRONMENT_H_ */
