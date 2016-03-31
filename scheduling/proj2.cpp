// proj2.cpp
//
// CPU scheduling simulation.
// 2016 (c) zubernetes
#include "ready_queue.h"

void get_input_from_cli();
std::queue<PCB*> do_infile();

int main(int argc, char **argv) {
    std::queue<PCB*> q;
    PCB *p = new PCB();

    if (argc < 2) {
        printf("Usage: proj2 input_file [FCFS|RR|SJF] [time_quantum]\n");
        return 0;
    } 

    p->setProcessID(1);
    p->setArrivalTime(0);
    p->setBurstSize(10);

    q = do_infile();

    while (!q.empty()) {
        std::cout << "Take a look: " 
                  << q.back()->getProcessID()
                  << "\n";
        q.pop();
    }

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

std::queue<PCB*> do_infile() {
    int x, count = 0;
    std::queue<PCB*> q;
    PCB *p = new PCB();

    std::fstream f;
    f.open("input_file", std::fstream::in); 

    while (!f.eof()) {
        if (count < 3) {
            switch (count) {
                case 0:
                    f >> x;
                    std::cout << x << ' ';
                    p->setProcessID(x);
                    break;
                case 1:
                    f >> x;
                    std::cout << x << ' ';
                    p->setArrivalTime(x);
                    break; 
                case 2:
                    f >> x;
                    std::cout << x << ' ';
                    p->setBurstSize(x);
                    break;
            }
            count++;
        } else {
            std::cout << '\n';
            q.push(p);
            count = 0;
        }
    }
    
    f.close();
    return q;
}
