/*
 * Vertex.h
 * This class represents Vertex object
 * Created on: May 13, 2019
 * Author: Evya
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <memory>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <string>
#include <limits>

#include "Warehouse.h"
#include "Edge.h"

using namespace std;

class Vertex{

private:

	string name;
	int d; // the d[v] of the vertex
	shared_ptr<Vertex> prevVertex; //save the path to the prev to restore the path
	vector<shared_ptr<Warehouse>> warehouseList;
	vector<shared_ptr<Edge>> edgesGroup;

public:

	Vertex(const string &name);
	Vertex(const Vertex &v);
	Vertex &operator=(const Vertex &v);
	Vertex(Vertex &&v);
	Vertex &operator=(Vertex &&v);

	void addWarehouse(shared_ptr<Warehouse> ware);
	const string& getName()const;
	int getD()const;
	vector<shared_ptr<Warehouse>>& getWarehouseList();
	vector<shared_ptr<Edge>>& getedgesGroup();
	void setD(int di);
	double getWaitingTime()const;
	void setWaitingTime(int a);
	void setPrevVertex(shared_ptr<Vertex> p);
	shared_ptr<Vertex> getPrevVertex();
	void sortWarehouseList();
	void sortTheEdgesGroup();

	virtual  ~Vertex();

};
#endif
