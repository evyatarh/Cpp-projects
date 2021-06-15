


#ifndef DEFENSIVEPACKET_H_
#define DEFENSIVEPACKET_H_

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DefensivePacket {

private:

	int size;
	int father;
	double propability;
	int adjustmentStrength;
	vector<bool> defVec;


public:

	DefensivePacket();
	DefensivePacket(const double prop,const int size);
	DefensivePacket(const DefensivePacket&);
	virtual DefensivePacket& operator=(const DefensivePacket&);
	virtual vector<bool> & getVec();
	virtual int getFather()const;
	virtual void setFather(int f);
	virtual void setDefenseSize(int siz);
	virtual void setAdjusment(int adj);
	virtual int getAdjusment();
	virtual void setPropability(double prop) = 0;
	virtual double getPropability();
	virtual void pushRandValuesToVec();
	virtual ~DefensivePacket() = 0;
};

#endif /* DEFENSIVEPACKET_H_ */
