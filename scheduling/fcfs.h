#ifndef FCFS_H
#define FCFS_H

void fcfs_sanity(std::queue<PCB*>);
void operateFCFS(std::queue<PCB*>);

void fcfs_sanity(std::queue<PCB*> q) {
    std::queue<PCB*> copy(q);

    while (!copy.empty()) {
        std::cout << "Process ID: " << copy.front()->getProcessID()
            << std::endl;
        std::cout << "Arrival Time: " << copy.front()->getArrivalTime()
            << std::endl;
        std::cout << "Burst Size: " << copy.front()->getBurstSize()
            << std::endl;
        copy.pop();
    }

}

void operateFCFS(std::queue<PCB*> q) {
    int workComplete = 0, 
        process      = 0, 
        arrivalTime  = 0,
        burstTime    = 0,
        systemTime   = 0;
    while(!q.empty()) {
        process     = q.front()->getProcessID();
        arrivalTime = q.front()->getArrivalTime();
        burstTime   = q.front()->getBurstSize();
        while(workComplete < burstTime) { 
            std::cout << "<system time " << systemTime << "> process " <<
               process << " is runnning" << std::endl;
            workComplete++;
            systemTime++;
            if (workComplete == burstTime) {
                std::cout << "<system time " << systemTime << "> process " <<
                   process << " is finished......." << std::endl;
            }
        }
        q.pop();
        workComplete = 0;
    }
    std::cout << "<system time " << systemTime << "> All processes " <<
       "finish...................." << std::endl;
    
}

#endif
