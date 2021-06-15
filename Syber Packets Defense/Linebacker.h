

#ifndef LINEBACKER_H_
#define LINEBACKER_H_

#include "DefensivePacket.h"

class Linebacker: public virtual DefensivePacket {


public:
	Linebacker();
	Linebacker(const Linebacker&);
	Linebacker(const int n,const int si);
	Linebacker& operator=(const Linebacker& cor);
	void setPropability(double prop);
	virtual ~Linebacker();

};

#endif /* LINEBACKER_H_ */
