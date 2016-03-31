// proj2.cpp
//
// CPU scheduling simulation.
// 2016 (c) zubernetes
#include "ready_queue.h"

void get_input_from_cli();
int  do_infile();

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Usage: proj2 input_file [FCFS|RR|SJF] [time_quantum]\n");
        return 0;
    } 

    if (!do_infile()) 
        std::cout << "Success, exiting.\n";
    else
        std::cout << "Error, I think\n";

    return 0;
}

void get_input_from_cli() {
    int z = 0;
    PCB *p = new PCB(); 
   
    std::cout << "Enter the process ID: ";
    std::cin >> z;
    p->setProcessID(z);
    std::cout << "The process ID is: " 
              << p->getProcessID() << '\n';

    std::cout << "Enter the arrival time: ";
    std::cin >> z;
    p->setArrivalTime(z);
    std::cout << "The arrival time is: " 
              << p->getArrivalTime() << '\n';

    std::cout << "Enter the burst time: ";
    std::cin >> z;
    p->setBurstSize(z);
    std::cout << "The burst time is: " 
              << p->getBurstSize() << '\n';
}

int do_infile() {
    int x; 
    std::fstream f;
    f.open("input_file", std::fstream::in); 

    while (!EOF) {
        std::fstream::in >> x;
        std::cout << x << '\n';
    }
    
    f.close();
    return 0;
}
