/*
 * Edge.cpp
 *
 * Created on: May 13, 2019
 * Author: Evya
 */

#include "Edge.h"


/******************** default c'tor method **************************/
Edge::Edge():from(""),to(""),passingAverageTime(0) {}


/******************** c'tor method **************************/
Edge::Edge(const string &from,const string &to,int weight):from(from),
		to(to),passingAverageTime(weight){}


/******************** copy c'tor method **************************/
Edge::Edge(const Edge &edg):from(edg.from),to(edg.to),passingAverageTime(edg.passingAverageTime){}


/******************** move set method **************************/
Edge& Edge::operator=(const Edge &edg){ //copy set operator
	if(this!=&edg){
		this->from = edg.from;
		this->to = edg.to;
		this->passingAverageTime = edg.passingAverageTime;
	}
	return *this;
}



/******************** move c'tor method **************************/
Edge::Edge(Edge &&edg){

	this->from = edg.from;
	edg.from.clear();
	this->to = edg.to;
	edg.to.clear();
	this-> passingAverageTime = edg.passingAverageTime;
	edg.passingAverageTime = 0;


}


/******************** move set method **************************/
Edge& Edge::operator=(Edge &&edg){
	if(this!=&edg){
		this->from = edg.from;
		edg.from = "";
		this->to = edg.to;
		edg.to = "";
		this->passingAverageTime = edg.passingAverageTime;
		edg.passingAverageTime = 0;
	}
	return *this;
}


/******************** edgeUpdatePassingAverageTime method **************************/
void Edge::edgeUpdatePassingAverageTime(int w,bool flag){
	setPassingAverageTime((flag==true?int((passingAverageTime + w) /2):int(passingAverageTime + w)));
	//this fucntion update the edges of the distances graph if some of the edges exits already
}


/******************** setFrom method **************************/
void Edge::setFrom(const string& s){from = s;}


/******************** setTo method **************************/
void Edge::setTo(const string& s){to = s;}


/******************** setPassingAverageTime method **************************/
void Edge::setPassingAverageTime(int p){passingAverageTime = p;}


/******************** getTo method **************************/
const string& Edge::getTo()const{return to;}


/******************** getFrom method **************************/
const string& Edge::getFrom()const{return from;}


/******************** getPassingAverageTime method **************************/
int Edge::getPassingAverageTime()const{return passingAverageTime;}


/******************** comparePassingAverageTime method **************************/
bool Edge::comparePassingAverageTime(int weight)const{return passingAverageTime < weight;}


/******************** d'tor method **************************/
Edge::~Edge() {}

