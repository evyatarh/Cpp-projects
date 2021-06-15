/*
 * Edge.h
 * This class represents Edge object
 * Created on: May 13, 2019
 * Author: Evya
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <iostream>

using namespace std;

class Edge {

private:

	string from,to;
	int passingAverageTime;

public:

	Edge();
	Edge(const Edge &edg);
	Edge(const string &from,const string &to,int weight);
	Edge& operator=(const Edge &edg);
	Edge(Edge &&edg);
	Edge& operator=(Edge &&edg);

	bool comparePassingAverageTime(int weight)const;
	void setFrom(const string& s);
	void setTo(const string& s);
	void setPassingAverageTime(int p);
	void edgeUpdatePassingAverageTime(int w,bool flag);
	const string& getTo()const;
	const string& getFrom()const;
	int getPassingAverageTime()const;

	virtual ~Edge();
};

#endif /* EDGE_H_ */
