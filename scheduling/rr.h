#ifndef RR_H
#define RR_H

int operateRR(std::vector<PCB*>, int);

int operateRR(std::vector<PCB*> v, int q) {
    std::vector<PCB*>::iterator it;
    int process       = 0,
        arrivalTime   = 0,
        burstTime     = 0,
        systemTime    = 0,
        wait_time     = 0,
        quantum       = q,
        processNum    = 0,
        difference    = 0,
        containerSize = v.size();

    while(!v.empty()) {
        // calculate average time of execution
        struct timeval wait_start, wait_stop;
        wait_start.tv_usec = 0, wait_stop.tv_usec = 0;
        gettimeofday(&wait_start, NULL);

        process      = v[processNum]->getProcessID();
        arrivalTime  = v[processNum]->getArrivalTime();
        burstTime    = v[processNum]->getBurstSize();

        for (int i = 0; i < quantum; i++) {
            std::cout << "<system time " << systemTime
                      << "> process "    << process
                      << " is runnning " << " : "
                      << burstTime       << std::endl;
            systemTime++;
        }

        difference = burstTime - q;
        v[processNum]->setBurstSize(difference);

        gettimeofday(&wait_stop, NULL);
        wait_time = ((wait_stop.tv_sec - wait_start.tv_sec) * 1000000 +
            wait_stop.tv_usec - wait_start.tv_usec);

        processNum++;
        

        if (v[processNum]->getBurstSize() <= 0) {
            v.erase(v.begin()+processNum);
        }

        if (processNum >= containerSize-1)
            processNum = 0;
    }
    std::cout << "<system time " << systemTime << "> All processes " <<
       "finish...................." << std::endl;
    return wait_time;
}

#endif
