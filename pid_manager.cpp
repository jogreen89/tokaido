// pid_manager.cpp 
//
// The PID manager class. Contains get/set methods for the bitset class
// found in the STL. This class is meant to illustrate how an operating
// system's PID manager may keep track of active or suspended processes
// (c) 2016 zubernetes

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <stdexcept>

#include "pid_manager.h"

#define MIN_PID 300
#define MAX_PID 5000

using namespace std;

PIDManager::PIDManager() {
    cout << "::PIDManager Object Initiated::" << endl;
}

int PIDManager::allocate_map(void) {
	// Initialize bitmap object of size 5000
    bitset<MAX_PID> bitmap;

    cout << "::Initialized a new bitset for representing PIDs::\n"; 

    // If 'any' of the bits are set in the bitmap, there
    // was an error in initialization, return status (-1)
    if (bitmap.any()) {
        return -1;
    } else {
        top = bitmap;
        return 1;
    }
}

int PIDManager::allocate_pid(void) {
	// If 'all' of the bits are set in the bitmap
	// there are no available PIDs 
    if (top.all()) {
        return -1;
    }

	// Test Suite - 01 
    // Number of PID allocations : 300
	// Sets 300 PIDs in PIDManger's bitset
    int num = 300,
            i = 0,
            range = MAX_PID - MIN_PID,
            repeats = 0;

    while (i < num) {
        // Seed for PID
        int r = rand() / 1 % range + 300;

		// If the bit at pos(i) is set, generate another pos(i)
        if (top.test(r)) {
            repeats++;
            r = rand() / 1 % range + 300;
        } else 
            top.set(r,1);
        i++;
    }
    cout << top << '\n' << "\'Note\' -- There were " 
		<< repeats << " repeats during allocation.\n";
    return 1;
}

void PIDManager::release_pid(int pid) {
    try {
    	cout << "Releasing PID: " << pid << endl;
        top.reset(pid);
    } catch (std::out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << '\n';
    }
    
}

std::bitset<MAX_PID> PIDManager::get_bitset() const {
    return top;
}
