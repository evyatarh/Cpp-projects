/*
 * Vertex.cpp
 *
 * Created on: May 13, 2019
 * Author: Evya
 */

#include "Vertex.h"

/******************** c'tor method **************************/
Vertex::Vertex(const string &name):name(name),
d(numeric_limits<int>::max()),prevVertex(nullptr){}


/******************** copy c'tor method **************************/
Vertex& Vertex::operator=(const Vertex &v){
	if(this!=&v){
		this->name = v.name;
		this->d = v.d;
		this->edgesGroup.clear();
		this->edgesGroup = v.edgesGroup;
		this->warehouseList.clear();
		this->warehouseList = v.warehouseList;
	}
	return *this;
}



/******************** move c'tor method **************************/
Vertex::Vertex(Vertex &&v):name(move(v.name)),d(v.d),prevVertex(move(v.prevVertex)){
	warehouseList.clear();
	warehouseList = move(v.warehouseList);
	edgesGroup.clear();
	edgesGroup = move(v.edgesGroup);
}


/******************** move set method **************************/
Vertex &Vertex::operator=(Vertex &&v){

	if(this!=&v){
		this->warehouseList.clear();
		this->warehouseList = v.warehouseList;
		this->edgesGroup.clear();
		this->edgesGroup = v.edgesGroup;
	}
	return *this;
}


/******************** getD method **************************/
int Vertex::getD()const{return d;}


/******************** setD method **************************/
void Vertex::setD(int di){d = di;}


/******************** sortWarehouseList method **************************/
void Vertex::sortWarehouseList(){

	sort(warehouseList.begin(), warehouseList.end(),
			[](shared_ptr<Warehouse> first, shared_ptr<Warehouse> sec) {
		return (first->getArrivel().compareDateAndTime(sec->getArrivel()));});
}


/******************** getWarehouseList method **************************/
vector<shared_ptr<Warehouse>>& Vertex::getWarehouseList(){return warehouseList;}


/******************** getedgesGroup method **************************/
vector<shared_ptr<Edge>>& Vertex::getedgesGroup(){return edgesGroup;}

/******************** getPrevVertex method **************************/
shared_ptr<Vertex> Vertex::getPrevVertex() { return prevVertex; }


/******************** setPrevVertex method **************************/
void Vertex::setPrevVertex(shared_ptr<Vertex> p) { prevVertex = p; }


/******************** getName method **************************/
const string& Vertex::getName() const{ return name; }


/******************** addWarehouse method **************************/
void Vertex::addWarehouse(shared_ptr<Warehouse> ware){warehouseList.push_back(ware);}


/******************** d'tor method **************************/
Vertex::~Vertex(){}

