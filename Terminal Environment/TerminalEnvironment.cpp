
#include "TerminalEnvironment.h"

/******************** c'tor method **************************/
TerminalEnvironment::TerminalEnvironment(){}

/********************copy c'tor method **************************/
TerminalEnvironment::TerminalEnvironment(const TerminalEnvironment &t){*this = t;}

/******************** touch method **************************/
void TerminalEnvironment::touch(const string &name){

	it = manager.find(name);

	if(it==manager.end()) //if the file does not exist so create one
		manager.insert(pair<string,FileBuiltIn* > (name,new FileBuiltIn(name)));

	else it->second->flushObject();


}

/******************** copy method **************************/
void TerminalEnvironment::copy(const string &source,const string &target){

	touch(target);
	it = manager.begin();
	map<string,FileBuiltIn*>::iterator it2 = manager.begin();
	checkIfTheFileExist(it,source);
	checkIfTheFileExist(it2,target);

	string writeTo;
	it->second->appendFile(writeTo);
	it2->second->writeToFile(writeTo);

}

/******************** remove method **************************/
void TerminalEnvironment::remove(const string &fileName){

	it = manager.begin();
	checkIfTheFileExist(it,fileName);
	manager.erase(it);
	delete it->second;
	std::remove(fileName.c_str()); //delete the file
}

/******************** move method **************************/
void TerminalEnvironment::move(const string &source,const string &target){

	copy(source,target);
	remove(source);
}

/******************** cat method **************************/
void TerminalEnvironment::cat(const string &fileName){

	it = manager.begin();
	checkIfTheFileExist(it,fileName);
	it->second->printAllTheFile();

}


/******************** head method **************************/
void TerminalEnvironment::head(const string &fileName,int n=10){

	it = manager.begin();
	checkIfTheFileExist(it,fileName);
	it->second->printTheHeadOfTheFile(n);

}

/******************** checkIfTheFileExist method **************************/
void TerminalEnvironment::checkIfTheFileExist(map<string,FileBuiltIn*>::iterator &it,const string &fileName) {
	it = manager.find(fileName);
	if(it==manager.end()) throw IOException(fileName);
}


/******************** tail method **************************/
void TerminalEnvironment::tail(const string &fileName,int n=10){

	it = manager.begin();
	checkIfTheFileExist(it,fileName);
	it->second->printTheEndOfTheFile(n);
}

/******************** runTerminal method **************************/
void TerminalEnvironment::runTerminal(){

	string buffer;
	string command,sFileName,tFileName;

	while(true){

		try{

			int num = -1;
			buffer=command=sFileName=tFileName="";

			getline(cin,buffer);
			istringstream instr(buffer);
			instr >> command >> sFileName;

			it = manager.find(sFileName); //find the file in the map

			if(!command.compare( "read")){

				instr >> num;
				if(num<0) throw InvalidUsageCommand("read FILENAME POSITION");

				const FileBuiltIn &temp = *it->second; //const ref for go to the const operator[]
				cout << temp[num] << endl;

			}

			else if(!command.compare( "write")){

				char c = 0;
				instr >> num >> c;

				if(num<0 || !c)
					throw InvalidUsageCommand("write FILENAME POSITION CHARACTER");

				if(it!=manager.end())(*it->second)[num] = c; //use the operator[]

			}

			else if(!command.compare( "touch")){
				if(!sFileName.compare(""))throw InvalidUsageCommand("touch FILENAME");
				it = manager.begin();
				touch(sFileName);
				}

			else if(!command.compare( "copy")){

				instr >> tFileName;

				if(!tFileName.compare(""))
					throw InvalidUsageCommand("copy SOURCE_FILENAME TARGET_FILENAME");

				copy(sFileName,tFileName);

			}

			else if(!command.compare( "remove")){
				if(!sFileName.compare(""))throw InvalidUsageCommand("remove FILENAME");
				remove(sFileName);
				}

			else if(!command.compare( "move")){
				instr >> tFileName;

				if(!tFileName.compare(""))
					throw InvalidUsageCommand("move SOURCE_FILENAME TARGET_FILENAME");

				move(sFileName,tFileName);

			}

			else if(!command.compare( "cat")){
				if(!sFileName.compare(""))throw InvalidUsageCommand("cat FILENAME");
				cat(sFileName);
				}

			else if(!command.compare( "head")){
				if(!sFileName.compare(""))throw InvalidUsageCommand("head FILENAME [n]");
				instr >> num;

				if(num<0) head(sFileName); //head version without parameter
				else head(sFileName,num);

			}

			else if(!command.compare( "tail")){
				if(!sFileName.compare(""))throw InvalidUsageCommand("tail FILENAME [n]");
				instr >> num;

				if(num<0) tail(sFileName);  //tail version without parameter
				else tail(sFileName,num);

			}

			else if(!command.compare( "exit")){break;}

			else throw InvalidCommand();
		} // close the try

		catch(TerminalEnvironment::InvalidCommand &er){	er.printError();}

		catch(TerminalEnvironment::IOException &e){e.printError();}

		catch(TerminalEnvironment::InvalidUsageCommand &err){err.printError();}

		catch(FileBuiltIn::OutOfBoundary &eer){eer.printError();}


	}
}

/******************** operator= method **************************/
TerminalEnvironment& TerminalEnvironment::operator=(const TerminalEnvironment &t){

	for(map<string,FileBuiltIn*>::const_iterator it = t.manager.begin();it!=t.manager.end();it++)
		manager.insert(pair<string,FileBuiltIn*>(it->first,it->second));
	return *this;
}
/******************** d'tor method **************************/
TerminalEnvironment::~TerminalEnvironment() {}


