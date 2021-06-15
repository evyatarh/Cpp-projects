
#include "Simulator.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main(int argc, char *argv[]) {

	Simulator s(argv[1],argv[2],argc);
	s.startTheSimulator();

	return 0;
}
