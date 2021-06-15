
#ifndef TACKLE_H_
#define TACKLE_H_


#include "DefensivePacket.h"

class Tackle: public virtual DefensivePacket {

public:
	Tackle();
	Tackle(const Tackle&);
	Tackle(const int n,const int si);
	Tackle& operator=(const Tackle& cor);
	void setPropability(double prop);
	virtual ~Tackle();
};

#endif /* TACKLE_H_ */
