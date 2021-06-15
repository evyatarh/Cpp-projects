

#include "Simulator.h"


/******************** c'tor method **************************/

Simulator::Simulator(const char *arg1,const char *arg2,const int &arc)
:generationBeat(0),stringsDimension(0)
{
	try{
	if (arc != 3) throw ArcException("");
	getConfigFromTheUser(arg1);
	getOffenseFromTheUser(arg2);
	}
	catch(Simulator::ArcException &eer){eer.printError();}
	catch(Simulator::IOException &eer){eer.printError();}
	catch(Simulator::InputErrorException &eer){eer.printError();}

}

/******************** copy c'tor method **************************/

Simulator::Simulator(const Simulator &sim):generationBeat(sim.generationBeat),
		stringsDimension(sim.stringsDimension){}



/******************** operator= method **************************/

Simulator& Simulator::operator=(const Simulator &sim){

	if(this != &sim){
		this->generationBeat = sim.generationBeat;
		this->stringsDimension = sim.stringsDimension;
		this->attackVec = sim.attackVec;
		this->originalDefensivePacket = sim.originalDefensivePacket;
		this->updatedDefensivePacket = sim.updatedDefensivePacket;
	}
	return *this;

}



/******************** getConfigFromTheUser method **************************/

void Simulator::getConfigFromTheUser(const char* arg1){

	srand(time(NULL));
	ifstream firstFile(arg1);  //open the file. if does not success will throw an error

	if (!firstFile) throw IOException(arg1);

	string s;

	// get the number of the strings dimension
	getline(firstFile,s);
	int n = stoi(s);
	if(n < MINSTRINGSDIMENSION || n > MAXSTRINGSDIMENSION)
		throw InputErrorException("Wrong Strings Dimension");

	stringsDimension = n;
	s.clear();
	getline(firstFile,s);

	int tack = s[0] - '0';
	int lineb = s[2] - '0';
	int cornerb = s[4] - '0';

	for (int i = 0; i < tack; ++i){

		Tackle *t = new Tackle(0.25,stringsDimension);
		t->pushRandValuesToVec();
		originalDefensivePacket.push_back(t);
	}

	for (int i = 0; i < lineb; ++i){
		Linebacker *l = new Linebacker(0,stringsDimension);
		l->pushRandValuesToVec();
		originalDefensivePacket.push_back(l);
	}

	for (int i = 0; i < cornerb; ++i) {
		Cornerback *c = new Cornerback(1/stringsDimension,stringsDimension);
		c->pushRandValuesToVec();
		originalDefensivePacket.push_back(c);
	}

	copy(originalDefensivePacket.begin(),originalDefensivePacket.end(),back_inserter(updatedDefensivePacket));

	getline(firstFile,s); // get the number of the generation number
	n = stoi(s);

	if(n > MAXGENERATION || n < 0)
		throw InputErrorException("Wrong Max Generation Size");

	generationBeat = n;

	firstFile.close();

}


/******************** powerOfDefense method **************************/

int Simulator::powerOfDefense(){

	for(unsigned int i = 0 ; i < updatedDefensivePacket.size() ; ++i){

		DefensivePacket * temp = updatedDefensivePacket[i];
		int max = 0;

		for (unsigned int j = 0; j < attackVec.size(); ++j) {

			int sum = 0;

			for (int k = 0; k < stringsDimension; ++k) {

				sum += ((temp->getVec()[k])*(1-attackVec[j][k])) +
						(attackVec[j][k]*(1-temp->getVec()[k])); // by the formula
			}

			sum = stringsDimension - sum;
			if(sum > max) max = sum;
			if (sum == stringsDimension) return i; // simulation stop condition
		}

		temp->setAdjusment(max); //power of defense for each packet
	}

	return -1;
}


/******************** getOffenseFromTheUser method **************************/

void Simulator::getOffenseFromTheUser(const char *arg2){

	//this method get the offense group from the file

	string s(arg2);
	ifstream seconedFile(arg2);

	if(!seconedFile) IOException(s);
	s.clear();

	getline(seconedFile,s);

	int attackSize = stoi(s);

	if(!attackSize)
		throw InputErrorException("The size of the attack group must be higher then 0");

	stringstream ss;

	vector<vector<bool>> vec(attackSize,vector<bool>(stringsDimension));
	int temp = attackSize;
	bool l;
	while(temp--){
		s.clear();
		ss.clear();
		getline(seconedFile,s);
		ss << s;

		for (int j = 0; j < stringsDimension; j++){
			ss >> l;
			vec[attackSize-temp-1][j] = l;
		}


	}
	copy(vec.begin(),vec.end(),back_inserter(attackVec));
	seconedFile.close();

}

/******************** switchStrings method **************************/

void Simulator::switchStrings(DefensivePacket * a,DefensivePacket * b){

	int t,s;
	srand(time(NULL));
	while(true){
		s = rand()% (stringsDimension - 1) ;
		t = rand()% stringsDimension ;
		if(s < t)break;
	}
	for (int i = s,j=0; i < t; ++i,++j) {

		bool val = a->getVec()[i];
		a->getVec()[i] = b->getVec()[i];
		b->getVec()[i] = val;

	}

}


/******************** startTheSimulator method **************************/

void Simulator::startTheSimulator(){

	srand(time(NULL));
	int ret;
	int rand_a;
	int rand_b;
	while(generationBeat--){

		ret = powerOfDefense();
		if(ret != -1) break;

		while(true){
			rand_a = (rand()% originalDefensivePacket.size());
			rand_b = (rand()% originalDefensivePacket.size());
			if(rand_a != rand_b)break;
		}
		DefensivePacket * rand1 (originalDefensivePacket[rand_a]);
		DefensivePacket * rand2 (originalDefensivePacket[rand_b]);

		rand1->setFather(rand_a);
		rand2->setFather(rand_b);

		switchStrings(rand1,rand2);

		sort(updatedDefensivePacket.begin(),updatedDefensivePacket.end(),
				[](DefensivePacket *a,DefensivePacket *b)->bool{
			return a->getAdjusment() > b->getAdjusment();}
		);

		updatedDefensivePacket.pop_back(); //remove the weakest adjustment string
		updatedDefensivePacket.pop_back(); //remove the seconed weakest adjustment string

		updatedDefensivePacket.push_back(rand1); //push the new ones
		updatedDefensivePacket.push_back(rand2);

		flipBitInPropebuility();

		//I sorted twice because the strongest at the end can be the last one who pushed.
		sort(updatedDefensivePacket.begin(),updatedDefensivePacket.end(),
				[](DefensivePacket *a,DefensivePacket *b)->bool{
			return a->getAdjusment() > b->getAdjusment();}
		);

	}

	printTheUpdatedPacket();
	printTheOriginalPacket();

	int help = 0;
	if(!ret) help = ret;


	//the first packet is the strongest unless we found the strongest befor the generation beats ended.
	for (int i = 0; i < stringsDimension; ++i)
		cout << updatedDefensivePacket[help]->getVec()[i] << " ";
	printType(updatedDefensivePacket[help]);
	cout << endl;

}

/******************** printType method **************************/

void Simulator::printType(const DefensivePacket *a){

	string s(typeid(*a).name() );
	char c1 =  s.c_str()[1];

	if(typeid(*a) != typeid(Tackle)) c1 = s.c_str()[2];

	cout <<  c1;

}

/******************** printTheUpdatedPacket method **************************/

void Simulator::printTheUpdatedPacket(){

	for (unsigned int i = 0; i < updatedDefensivePacket.size(); ++i) {

		for (int j = 0; j < stringsDimension; ++j)
			cout << updatedDefensivePacket[i]->getVec()[j] << " ";
		printType(updatedDefensivePacket[i]);
		cout << endl;

	}
	cout << endl;
}

/******************** checkTheRc method **************************/

void Simulator::checkTheRc(){

	int cnt[updatedDefensivePacket.size()] = {0};

	for (unsigned int j = 0; j < updatedDefensivePacket.size(); ++j){
		int i = updatedDefensivePacket[j]->getFather();
		cnt[i]++;
	}

	for (unsigned int j = 0; j <originalDefensivePacket.size(); ++j)
		originalDefensivePacket[j]->setFather(cnt[j]);
}

/******************** flipBitInPropebuility method **************************/

void Simulator::printTheOriginalPacket(){

	checkTheRc();
	for (unsigned int i = 0; i < originalDefensivePacket.size(); ++i) {

		for (int j = 0; j < stringsDimension; ++j)
			cout << originalDefensivePacket[i]->getVec()[j] << " ";

		printType(originalDefensivePacket[i]);
		cout << " " << originalDefensivePacket[i]->getFather() << endl;

	}
	cout << endl;
}

/******************** flipBitInPropebuility method **************************/

void Simulator::flipBitInPropebuility(){

	srand(time(NULL));
	int ran;

	for (unsigned int i = 0; i < updatedDefensivePacket.size(); ++i) {

		for (int j = 0; j < stringsDimension; ++j) {

			if(typeid(*updatedDefensivePacket[i]) == typeid(Tackle)){
				ran = (rand() %  4);
				if(!ran) updatedDefensivePacket[i]->getVec()[j].flip();
			}

			if(typeid(*updatedDefensivePacket[i]) == typeid(Cornerback)){
				ran = (rand() % stringsDimension );
				if(!ran) updatedDefensivePacket[i]->getVec()[j].flip();
			}

			//if its a Linebacker type - the propability is 0 so it mean its stay the same.


		}
	}
}

/******************** d'tor method **************************/

Simulator::~Simulator() {}



