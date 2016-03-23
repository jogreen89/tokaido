/*
* (c) Jonathan Green
*/
#ifndef PID_MANAGER_PIDMANAGER_H
#define PID_MANAGER_PIDMANAGER_H

/* A bitset stores bits (elements with 
only two possible values: 0 or 1, true or false */
#include <bitset>

#define MIN_PID 300
#define MAX_PID 5000

class PIDManager {
public:
    PIDManager();

    int allocate_map(void);
    int allocate_pid(void);

    void release_pid(int pid);
    void print_bitset();

    std::bitset<MAX_PID> get_bitset() const ;

private:
    int val;
    std::bitset<MAX_PID> top;
};

#endif //PID_MANAGER_PIDMANAGER_H
