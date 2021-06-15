/*
 * Network.cpp
 *
 * Created on: May 13, 2019
 * Author: Evya
 */

#include "Network.h"

/******************** default c'tor method **************************/
Network::Network():output("output.dat") {}

/******************** c'tor method **************************/
Network::Network(const int &arc,char *files[]):output("output.dat"){

	if(!strcmp(files[1],"-f")){
		for(int i = 2; i < arc ; i++){
			if(!strcmp(files[i],"-p")){
				output = files[i+1];
				break;
			}
			getNetworkFromUser(files[i]);
		}
	}
}

/******************** copy c'tor method **************************/
Network::Network(const Network &net):boxesGraph(net.boxesGraph),
		shippingTimeGraph(net.shippingTimeGraph),output(net.output){}


/******************** copy set method **************************/
Network& Network::operator=(const Network &net){
	if(this!=&net){
		this->boxesGraph = net.boxesGraph;
		this->shippingTimeGraph = net.shippingTimeGraph;
		this->output = net.output;
	}
	return *this;
}



/******************** move c'tor method **************************/
Network::Network(Network &&net){
	this->boxesGraph = move(net.boxesGraph);
	this->shippingTimeGraph = move(net.shippingTimeGraph);
	this->output = net.output;
	net.output.clear();
}


/******************** move set method **************************/
Network& Network::operator=(Network &&net){
	if(this != &net){
		this->boxesGraph = move(net.boxesGraph);
		this->shippingTimeGraph = move(net.shippingTimeGraph);
		this->output = net.output;
		net.output.clear();
	}
	return *this;
}



/******************** loadData method **************************/
void Network::loadData(const string &name){
	getNetworkFromUser(name.c_str());
	cout << "Update was successful." << endl;

}

/******************** run method **************************/
void Network::run(){

	string option,fileName,source_node;

	while (true){
		try{
			option.clear();
			fileName.clear();
			getline(cin,fileName,'\n');

			size_t size = fileName.find(",");
			option = fileName.substr(0,size);
			fileName.erase(0,size+1);
			size = fileName.find(",");
			source_node = fileName.substr(0,size);
			fileName.erase(0,size+1);


			if (!option.compare("open")) loadData(fileName);

			else if (!fileName.compare("outbound")) outbound(option);

			else if (!fileName.compare("inbound")) inbound(option);

			else if (!source_node.compare("inventory")) inventory(option,fileName);

			else if (!option.compare("shortest")) shortest(source_node,fileName);

			else if(!fileName.compare("print")) print();

			else if (!option.compare("exit")) exit(1);

			else throw InvalidArguments(
					"USAGE: 'open',<file> *or*\n"
					"<node>,'outbound'/'inbound' *or*\n"
					"<node>,'inventory',dd/mm HH:mm *or*\n"
					"<node>,<node>,'shortest' *or*\n"
					"‘exit’ *to terminate*\n");

		}
		catch(InvalidArguments &eer){eer.printError();}
		catch(invalid_argument &eer){cerr << eer.what()<< endl;}
	}

}



/******************** outbound method **************************/
void Network::outbound(const string &ware){

	shared_ptr<Vertex> v = shippingTimeGraph.getVertex(ware);

	if(!v) throw InvalidArguments(ware + " Does not exist in the database\n");
	if(!v->getedgesGroup().size()) throw InvalidArguments(ware + ": no outbound nodes\n");

	for(auto &edge : v->getedgesGroup())
		cout << edge->getTo() << "," << edge->getPassingAverageTime() << endl;

}



/******************** inbound method **************************/
void Network::inbound(const string &ware){

	bool flag = false;
	shared_ptr<Vertex> v = shippingTimeGraph.getVertex(ware);

	if(!v) throw InvalidArguments(ware + " Does not exist in the database\n");


	for(auto &u : shippingTimeGraph.getVertexList()){
		for(auto &edge : u->getedgesGroup())
			if(!edge->getTo().compare(v->getName())){
				flag = true;
				cout << edge->getFrom() << "," << edge->getPassingAverageTime() << endl;
			}
	}
	if(!flag)throw InvalidArguments(ware + ": no inbound nodes\n"); //if non of the edges get in the vertex

}

/******************** inventory method **************************/
void Network::inventory(const string &source,const string &date){

	shared_ptr<Vertex> v = boxesGraph.getVertex(source);
	Date d(date);
	int weight = 0;

	if(!v) throw InvalidArguments(source + " Does not exist in the database\n");

	v->sortWarehouseList();

	if(!d.compareDateAndTime(v->getWarehouseList()[0]->getArrivel()) &&
			d.compareDateAndTime(v->getWarehouseList()[0]->getdepa()))
		for(shared_ptr<Warehouse> u : v->getWarehouseList()) weight += u->getNumOfBoxes();

	cout << weight << endl;

}

/******************** shortest method **************************/
void Network::shortest(const string &source,const string &target){
	shippingTimeGraph.dijkstra(source,target);
}

/******************** print method **************************/
void Network::print(){

	ofstream ofs(output);

	if(!ofs) throw IOException(output);

	ofs << "The boxes graph:" << endl;

	for(auto &v: boxesGraph.getVertexList()){
		ofs << "source Vertex " << v->getName() << " is goings to :" << endl;
		if(v->getedgesGroup().empty()) ofs << "Nowhere!!!!" << endl;
		for(auto &e: v->getedgesGroup())
			ofs << e->getTo() << ",in this warehouse there is " << e->getPassingAverageTime() << " boxes." << endl;

	}
	ofs << endl;

	ofs << "The shipping graph:" << endl;


	for(auto &v: shippingTimeGraph.getVertexList()){
		ofs << "from Vertex " << v->getName() << " there is a shipping to :" << endl;
		if(v->getedgesGroup().empty()) ofs << "Nowhere!!!!" << endl;
		for(auto &e: v->getedgesGroup())
			ofs << e->getTo() << " in " << e->getPassingAverageTime() << " minutes." <<  endl;

	}


	ofs.close();
}

/******************** getNetworkFromUser method **************************/
void Network::getNetworkFromUser(const char* filename){

	try{

		string s(filename);
		ifstream filen(filename);
		int line_cnt = 1;
		if(!filen) throw IOException(s);

		string cityName, arrivelTime, depaturTime, num_of_boxes, prev_city, prev_exit;
		getline(filen, cityName, ',');       //the delimiter is ','
		getline(filen, depaturTime, '\n');
		checkWarehouseName(cityName,s,line_cnt);  //check the source warehouse name
		Date departure(depaturTime);
		Date arrivel(depaturTime); //same as departure time for convenience for the source vertrx
		shared_ptr<Warehouse> source(new Warehouse( cityName,arrivel,departure,0));
		shippingTimeGraph.insertVertex(cityName,source);
		boxesGraph.insertVertex(cityName,source);
		string prev = cityName;
		int sum = 0;

		while (!filen.eof()){

			cityName.clear();
			arrivelTime.clear();
			depaturTime.clear();
			num_of_boxes.clear();

			line_cnt++;
			getline(filen, cityName, ',');
			checkWarehouseName(cityName,s,line_cnt);
			getline(filen, arrivelTime, ',');
			getline(filen, num_of_boxes, ',');
			checkIfValid(num_of_boxes,s,line_cnt);
			getline(filen, depaturTime, '\n');
			Date dep(depaturTime);
			Date arr(arrivelTime);
			shared_ptr<Warehouse> wr(new Warehouse(cityName,arr,dep,stoi(num_of_boxes)));
			shippingTimeGraph.insertVertex(cityName,wr);
			//sending flag = true if we at the shipping graph because if the edge is exist we do an avg
			shippingTimeGraph.insertEdge(prev,cityName,departure.getTheDiffrentTime(arr),true);
			boxesGraph.insertVertex(cityName,wr);
			boxesGraph.insertEdge(source->getName(),cityName,wr->getNumOfBoxes(),false);

			prev = cityName;
			departure = move(dep);
			sum += wr->getNumOfBoxes();
		}
		shared_ptr<Vertex> t = boxesGraph.getVertex(source->getName());
		t->getWarehouseList()[0]->setNumOfBoxes((
				t->getWarehouseList()[0]->getNumOfBoxes() + sum) *(-1));
		filen.close();
	}
	catch(IOException &eer){eer.printError();}
	catch(InputErrorException &eer){eer.printError();}

}


/******************** checkIfValid method **************************/
void Network::checkIfValid(const string &num_of_boxes,const string &filename,int line){
	if(!(stoi(num_of_boxes) > 0)) throw InputErrorException(filename,line);
}


/******************** checkWarehouseName method **************************/
void Network::checkWarehouseName(const string &name,const string &filename,int line){

	if (name.length() > MAX_WAREHOUSE_NAME_LENGTH)
		throw InputErrorException(filename,line);

	for (unsigned int i = 0; i < name.length(); i++){
		if (!isalpha(name[i]) && !isspace(name[i]))
			throw InputErrorException(filename,line);
	}
}


/******************** d'tor method **************************/
Network::~Network() {}

