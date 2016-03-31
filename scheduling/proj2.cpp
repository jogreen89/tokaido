// proj2.cpp
//
// CPU scheduling simulation.
// 2016 (c) zubernetes
#include "ready_queue.h"
#define BUF_SIZE 50

int  getMaxCount();
void setMaxCount(int);
void get_input_from_cli();
int* do_infile();

int max_count = 0;

int main(int argc, char **argv) {
    std::queue<PCB*> q;
    PCB *p = new PCB();
    int* a;
    int count = 0;

    if (argc < 2) {
        printf("Usage: proj2 input_file [FCFS|RR|SJF] [time_quantum]\n");
        return 0;
    } 


    a = do_infile();

    for (int j = 0; j < getMaxCount(); j++) {
        std::cout << a[j] << " ";
        p->setProcessID(a[j]);
        j++;
        p->setArrivalTime(a[j]);
        j++;
        p->setBurstSize(a[j]);

        q.push(p);

        count++;
        if (count > 2) {
            std::cout << std::endl;
            count = 0;
        }
    }

    std::cout << "q:size " << q.size() << std::endl;

    return 0;
}

void setMaxCount(int x) {
    max_count = x;
}

int getMaxCount() {
    return max_count;
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

int* do_infile() {
    int x = 0,
        i = 0,
        y = 0,
        z = 0,
        count = 0;
    static int a[BUF_SIZE];
    std::queue<PCB*> q;
    PCB *p = new PCB();

    std::fstream f;
    f.open("input_file", std::fstream::in); 

    while (f >> x) {
        std::cout << x << " ";
        a[i] = x;
        count++;
        i++;
        if (count > 2) {
            std::cout << std::endl;
            count = 0;
        }
    }
    f.close();
    setMaxCount(i);
    return &a[0];
}



