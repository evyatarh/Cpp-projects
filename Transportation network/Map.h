

#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "Pair.h"

using namespace std;

template<class Key,class Value>
class Map {

private:

	int size;
	int numOfKeys;
	Pair<Key,Value> *map;

public:

	Map(const int &size):size(size),numOfKeys(0){map = new Pair<Key,Value>[size];}
	void put(const Key&,const Value&);
	void deleteOne(const Key &key);
	Value* get(const Key&);
	void deleteAll();
	void print()const;
	int getNumOfKeys()const;
	void incNumOfKeys(){numOfKeys++;};
	void decNumOfKeys(){numOfKeys--;};
	virtual ~Map(){delete[] map;}

	/******************** operator[] method **************************/
	//this operator will let put values at the specific key
	Value& operator[](const Key& key){
		for( int i = 0; i < size ; ++i) {
			if( map[i].getFirst() == key){
				return map[i].getSecond();
			}
		}
		return 0;
	}

	/******************** const operator[] method **************************/
	//this operator let get the specific value that connect to the key. not for set
	const Value& operator[](const Key& key)const{
		for (int i = 0; i < size; ++i) {
			if( map[i].getFirst() == key){
				return map[i].getSecond();
			}
		}
		return 0;
	}

	/******************** copyAndReallocating method **************************/
	void copyAndReallocating(const int &originalSize, const int &newSize){

		Pair<Key,Value> *temp = new Pair<Key,Value>[originalSize];

		for(int i=0;i<originalSize;i++) temp[i]=map[i];

		delete[] map;

		map = new Pair<Key,Value>[newSize];
		for(int i=0;i<newSize;i++){
			if(i==originalSize)break;
			map[i]=temp[i];
		}

		delete[] temp;
	}


};

/******************** put method **************************/
template<class Key, class Value>
void Map<Key, Value>::put(const Key& key, const Value& val) {


	if(!numOfKeys){ //if the map is empty
		map[0].setFirst(key);
		map[0].setSecond(val);
		incNumOfKeys();
		return;
	}

	for( int i =0;i< numOfKeys;i++){ //if the key already exist so put the new value at the same key
		if(map[i].getFirst() == key){
			map[i].setSecond(val);
			return;
		}

	}


	incNumOfKeys();

	if(numOfKeys>size){
		copyAndReallocating(size,size+1);
		size = size + 1;
	}


	for(int i=0;i<numOfKeys;i++){
		if( key<map[i].getFirst()){
			Pair<Key,Value> *temp = new Pair<Key,Value>[size-i];

			for(int j=i,k=0;j<size;j++,k++) temp[k] = map[j];

			map[i].setFirst(key);
			map[i].setSecond(val);

			int k=0;
			int t=i+1;
			for (;t < size;k++,t++) map[t] = temp[k];
			delete[] temp;
			return;
		}
	}
	//if the key is the grater from all the keys
	map[numOfKeys-1].setFirst(key);
	map[numOfKeys-1].setSecond(val);


}

/******************** get method **************************/
template<class Key, class Value>
Value* Map<Key, Value>::get(const Key& key) {

	for(int i =0;i<size;i++){
		if(map[i].getFirst() == key){
			return &(map[i].getSecond());
		}
	}
	return 0;
}

/******************** deleteOne method **************************/
template<class Key, class Value>
void Map<Key, Value>::deleteOne(const Key &key){

	for(int i =0;i<size;i++){

		if(map[i].getFirst() == key){

			if(i != size - 1)
				for(int j=i+1;j<size;j++) map[j-1] = map[j];

			decNumOfKeys();
			copyAndReallocating(numOfKeys,numOfKeys);
		}
	}
}

/******************** deleteAll method **************************/
template<class Key, class Value>
void Map<Key, Value>::deleteAll(){

	delete[] map;
	map = new Pair<Key,Value>[size];
	numOfKeys = 0;
}

/******************** print method **************************/
//this method print the map keys and values
template<class Key, class Value>
void Map<Key, Value>::print()const{
	for(int i =0;i<numOfKeys;i++) cout << map[i];
}

/******************** getNumOfKeys method **************************/
template<class Key, class Value>
int Map<Key, Value>::getNumOfKeys()const{return numOfKeys;}


#endif /* MAP_H_ */
