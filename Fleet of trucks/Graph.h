/*
 * Graph.h
 * This class represents a Graph object
 * Created on: May 13, 2019
 * Author: Evya
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <queue>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include "Vertex.h"
#include "Warehouse.h"

using namespace std;

class Graph{

private:

	vector<shared_ptr<Vertex>> vertexList;

public:

    Graph();
    Graph(const Graph &g);
    Graph(Graph &&g);
    Graph &operator=(const Graph &g);
    Graph &operator=(Graph &&g);

    vector<shared_ptr<Vertex>>& getVertexList();
    void insertVertex(const string &name, shared_ptr<Warehouse> w);
    void insertEdge(const string &from, const string &to, int wight,bool flag);
    shared_ptr<Vertex> getVertex(const string &name);
    void dijkstra(const string &source,const string &end);
    void printRecursivelyThePath(shared_ptr<Vertex> prev)const;

    virtual  ~Graph();

    //comperator class for the minimum heap on dijkstra
	class Comperator{
	public:
		bool operator()(shared_ptr<Vertex> first, shared_ptr<Vertex> sec){
			return first->getD() > sec->getD();
		}

	};

};

#endif //GRAPH_H
