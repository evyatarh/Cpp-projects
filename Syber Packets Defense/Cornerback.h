


#ifndef CORNERBACK_H_
#define CORNERBACK_H_

#include "DefensivePacket.h"

class Cornerback: public virtual DefensivePacket {

public:
	Cornerback();
	Cornerback(const Cornerback&);
	Cornerback(const int n,const int si);
	Cornerback& operator=(const Cornerback& cor);
	void setPropability(double prop);
	virtual ~Cornerback();
};

#endif /* CORNERBACK_H_ */
