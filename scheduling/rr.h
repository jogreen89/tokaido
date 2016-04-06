#ifndef RR_H
#define RR_H

int operateRR(std::vector<PCB*>, int);

int operateRR(std::vector<PCB*> v, int q) {

    std::vector<PCB*>::iterator it;
    int process       = 0,
        arrivalTime   = 0,
        burstSize     = 0,
        systemTime    = 0,
        wait_time     = 0,
        quantum       = q,
        processNum    = 0,
        difference    = 0;

    while(!v.empty()) {
        struct timeval wait_start, wait_stop;           // 
        wait_start.tv_usec = 0, wait_stop.tv_usec = 0;  // Calculate average time of execution.
        gettimeofday(&wait_start, NULL);                //

        process      = v[processNum]->getProcessID();
        arrivalTime  = v[processNum]->getArrivalTime();
        burstSize    = v[processNum]->getBurstSize();

        for (int i = 0; i < quantum; i++) {
            std::cout << "<system time " << systemTime
                      << "> process "    << process
                      << " is running "  << std::endl;
            systemTime++;
        }

        difference = burstSize - q;
        v[processNum]->setBurstSize(difference);

        if (burstSize <= 0) {
            v.erase(v.begin()+processNum);
        }

        processNum++;
        if (processNum >= v.size() - 1)
            processNum = 0;

        gettimeofday(&wait_stop, NULL);
        wait_time = ((wait_stop.tv_sec - wait_start.tv_sec) * 1000000 +
            wait_stop.tv_usec - wait_start.tv_usec);
    }
    std::cout << "<system time " << systemTime << "> All processes " <<
       "finish...................." << std::endl;
    return wait_time;
}

#endif
