/*
 * Graph.cpp
 *
 * Created on: May 13, 2019
 * Author: Evya
 */

#include "Graph.h"



/******************** default c'tor method **************************/
Graph::Graph():vertexList(){}


/******************** copy c'tor method **************************/
Graph::Graph(const Graph &g){vertexList = g.vertexList;}


/******************** move c'tor method **************************/
Graph::Graph(Graph &&g){
	vertexList = move(g.vertexList);
	g.vertexList.clear();
}


/******************** copy set method **************************/
Graph& Graph::operator=(const Graph &g){
	if(this != &g){
		vertexList = g.vertexList;
	}
	return *this;
}


/******************** move set method **************************/
Graph& Graph::operator=(Graph &&g){
	if(this != &g){
		vertexList = move(g.vertexList);
		g.vertexList.clear();
	}
	return *this;
}


/******************** insertVertex method **************************/
void Graph::insertVertex(const string &name, shared_ptr<Warehouse> w){

	for (auto &v : vertexList){
		if (!v->getName().compare(name)){
			if(v->getName().compare(w->getName())) v->addWarehouse(w);
			return;
		}
	}
	shared_ptr<Vertex> newVertex(new Vertex(name));
	newVertex->addWarehouse(w);
	vertexList.push_back(newVertex);
}


/******************** insertEdge method **************************/
void Graph::insertEdge(const string &from,const string &to, int wight,bool flag){

	for (auto &v : vertexList){
		if (!v->getName().compare(from)){
			for (shared_ptr<Edge> edge : v->getedgesGroup()){
				if (!edge->getTo().compare(to)){
					edge->edgeUpdatePassingAverageTime(wight,flag); // update the edge if its already exists
					return;
				}
			}
			shared_ptr<Edge> newEdge(new Edge(from,to, wight)); //adding new edge to the edgesGroup
			v->getedgesGroup().push_back(newEdge);
			break;
		}
	}
}


/******************** getVertexList method **************************/
vector<shared_ptr<Vertex>>& Graph::getVertexList(){return vertexList;}


/******************** getVertex method **************************/
shared_ptr<Vertex> Graph::getVertex(const string &name){
	for (shared_ptr<Vertex> v : vertexList)
		if (!v->getName().compare(name)) return v;

	return nullptr;
}


/******************** dijkstra method **************************/
void Graph::dijkstra(const string &source,const string &target){
//implements dijkstra by how we learned at the algorithems course
	int infinity = std::numeric_limits<int>::max(); //infinite

	for (auto &v : vertexList) v->setD(infinity);

	priority_queue<shared_ptr<Vertex>, vector<shared_ptr<Vertex>>,Comperator > minHeap;
	shared_ptr<Vertex> s = getVertex(source);

	if(!s) throw invalid_argument(source + " Does not exist in the database\n");

	minHeap.push(s);

	for (auto &v : vertexList)	if (!v->getName().compare(source)) v->setD(0);

	while (!minHeap.empty()){

		shared_ptr<Vertex> v = minHeap.top();
		minHeap.pop();

		for (auto &edge : v->getedgesGroup()){
			for(auto &u : vertexList){
				if(!u->getName().compare(edge->getTo())){
					if(u->getD() > edge->getPassingAverageTime() + v->getD()){
						u->setD(edge->getPassingAverageTime() + v->getD());
						minHeap.push(getVertex(u->getName()));
						u->setPrevVertex(v);
					}
				}
			}
		}



	}
	shared_ptr<Vertex> endVertex = getVertex(target);
	if(!endVertex) throw invalid_argument(target + " Does not exist in the database\n");

	if (endVertex->getD() == infinity){
		cerr << "route unavailable" << endl;
		return;
	}

	printRecursivelyThePath(endVertex); //print recursively the path by using the prev vertex variable
}


/******************** printRecursivelyThePath method **************************/
void Graph::printRecursivelyThePath(shared_ptr<Vertex> prev)const{

	if(prev == nullptr) return;

	printRecursivelyThePath(prev->getPrevVertex());
	cout << "You at " << prev->getName() << " Warehouse. its took you " << prev->getD() <<
			" minutes to get down here from the starting Warehouse." << endl;

}


/******************** d'tor method **************************/
Graph::~Graph(){}

