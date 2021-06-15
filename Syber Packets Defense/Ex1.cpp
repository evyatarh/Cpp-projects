//============================================================================
// Description : Syber Packets Defense
//============================================================================

#include <iostream>
using namespace std;

#include "Simulator.h"

int main(int argc, char *argv[]) {

	Simulator start(argv[1],argv[2],argc);
	start.startTheSimulator();

	return 0;
}
