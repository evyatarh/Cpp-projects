

#ifndef PAIR_H_
#define PAIR_H_
#include <iostream>
#include <cstdlib>

using namespace std;

template <class Key,class Value>
class Pair {

private:

	Key key;
	Value value;

public:

	Pair(){};
	Pair(const Key& key,const Value& val):key(key),value(val){}
	Pair(const Pair& pair) : key(pair.key),value(pair.value){} //copy c'tor
	Key& getFirst() {return key;}
	Key getFirst() const{return key;}
	void setFirst(Key key) {this->key = key;}
	Value& getSecond(){return value;}
	Value getSecond()const {return value;}
	void setSecond(Value value) {this->value = value;}

	/******************** operator<< method **************************/
	//this operator put at the ostream of the pair the key and the value
	friend ostream& operator<<(ostream& out,Pair<Key,Value>& pa){
		out<< pa.key <<" "<< pa.value <<endl;
		return out;
	}

	/******************** operator= method **************************/
	Pair& operator=(const Pair &pa){
		this->key = pa.key;
		this->value = pa.value;
		return *this;
	}

	virtual ~Pair(){}
};

#endif /* PAIR_H_ */
