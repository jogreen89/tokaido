// pid_main.cpp
//
// The main driver for PIDManager that imitates the
// the function of a PID manager in modern operating systems.
// (c) 2016 zubernetes

#include <iostream>
#include "pid_manager.h"

using namespace std;

int main() {
	// Begin PIDManager test suite.
    PIDManager pidManager;
	
    if (pidManager.allocate_map()) {
        pidManager.allocate_pid();
    } else { 
        cout << "Error in bitset allocation. Aborting." << endl;
		exit(1);
	}
    return 0;
}
