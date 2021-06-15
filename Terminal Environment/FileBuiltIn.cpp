

#include "FileBuiltIn.h"
#include "TerminalEnvironment.h"

/******************** c'tor method **************************/
FileBuiltIn::FileBuiltIn(const string &fileName):fileI(new ifstream()),fileO(new ofstream()){
	fileO->open(fileName.c_str(),ios::out );
	fileI->open(fileName.c_str(),ios::in );
	if(fileO->fail())throw TerminalEnvironment::IOException(fileName);
	if(fileI->fail())throw TerminalEnvironment::IOException(fileName);

}

/********************copy c'tor method **************************/
FileBuiltIn::FileBuiltIn(const FileBuiltIn &f):fileI(f.fileI),fileO(f.fileO){}

/******************** printAllTheFile method **************************/
void FileBuiltIn::printAllTheFile()const{
	fileI->seekg(0);
	while(fileO->good()&&fileI->peek()!=EOF) cout << (char)fileI->get();
	cout << endLine; //use manipulator for practicing
	fileI->seekg(0);
}

/******************** printTheHeadOfTheFile method **************************/
void FileBuiltIn::printTheHeadOfTheFile(int n)const{

	fileI->seekg(0);

	while(fileI->peek()!=EOF && --n>=0) cout << (char)fileI->get();
	cout << endLine; //manipulator
	fileI->seekg(0);

}

/******************** getFileSize method **************************/
int FileBuiltIn::getFileSize()const{

	int ret = 0;

	if(fileO){
		fileO->seekp(0,ios::end);
		ret = fileO->tellp();
	}
	return ret;
}

/******************** printTheEndOfTheFile method **************************/
void FileBuiltIn::printTheEndOfTheFile(int n)const{

	int ret = getFileSize();
	int tail = getFileSize() - n;

	if(ret < n){fileI->seekg(0);tail = ret;}
	else fileI->seekg(tail);

	while( fileI->peek()!=EOF) cout <<(char) fileI->get();
	cout << endLine; //manipulator
	fileI->seekg(0);
}

/******************** flushObject method **************************/
void FileBuiltIn::flushObject(){fileO->flush();}

/******************** appendFile method **************************/
void FileBuiltIn::appendFile(string &app)const{

	app = "";
	fileI->seekg(0);

	while(fileI->good()&&fileI->peek()!=EOF) app+=fileI->get();
	fileI->seekg(0);

}

/******************** writeToFile method **************************/
void FileBuiltIn::writeToFile(string &staff){
	fileO->seekp(getFileSize());
	fileO->write(staff.c_str(),staff.length());
}


/******************** operator= method **************************/
FileBuiltIn& FileBuiltIn::operator=(const FileBuiltIn &t){

	fileO = t.fileO;
	fileI = t.fileI;
	return *this;
}

/******************** d'tor method **************************/
FileBuiltIn::~FileBuiltIn() {
	fileO->close(); //close the file and delete the allocated pointer
	fileI->close();
	delete fileO;
	delete fileI;
}
