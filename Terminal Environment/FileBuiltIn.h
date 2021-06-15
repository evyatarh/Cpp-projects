
#ifndef FILEBUILTIN_H_
#define FILEBUILTIN_H_

#include <fstream>
#include <iostream>
#include <exception>
#include <iomanip>
using namespace std;

class FileBuiltIn {

private:

	ifstream *fileI;
	ofstream *fileO;

public:

	FileBuiltIn(const string &fileName);
	FileBuiltIn(const FileBuiltIn &f); //copy c'tor
	FileBuiltIn& operator=(const FileBuiltIn &t);//copy set operator
	void printTheHeadOfTheFile(int n)const;
	void printAllTheFile()const;
	void printTheEndOfTheFile(int n)const;
	int getFileSize()const;
	void flushObject();
	void appendFile(string &app)const; //appended the fileO into a string
	void writeToFile(string &staff);
	virtual ~FileBuiltIn();


	/******************** const operator[] method **************************/
	//this operator let get the specific char from the fileO. not for set

	const FileBuiltIn& operator[]( int &location)const {

		if(getFileSize() <= location) throw OutOfBoundary();

		fileI->seekg(location);
		return *this;

	}

	/********************  operator[] method **************************/
	//this operator will let put char at the specific location into the fileO

	FileBuiltIn& operator[]( int &location){

		if(getFileSize()>=location) {
			fileO->seekp(location);
			return *this; //one index after end of fileO
		}
		throw OutOfBoundary();
	}


	/********************  endLine method **************************/
	//this is manipulator
	static ostream& endLine(ostream& out){return out << "\n" << flush;} //manipulator


	/********************  operator<< method **************************/
	//this operator is overloading for the ostream
	friend ostream& operator<<(ostream &out,const FileBuiltIn &f){
		out << (char)f.fileI->get();
		return out;
	}

	/********************  operator= method **************************/
	void operator=(char &c){
		fileO->put(c);
		fileO->seekp(0);
	}

	/********************  class OutOfBoundary **************************/
	//this class represent an exception from kind out of boundary
	class OutOfBoundary{

	public:
		//use default copy c'tor and copy set operator
		OutOfBoundary(){}
		void printError()const{
			cerr << "ERROR: out of Boundary" << endl;
		}
		virtual ~OutOfBoundary(){}
	};


};

#endif /* FILEBUILTIN_H_ */
