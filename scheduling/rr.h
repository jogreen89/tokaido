#ifndef RR_H
#define RR_H

int operateRR(std::vector<PCB*>, int);

int operateRR(std::vector<PCB*> v, int q) {
    std::vector<PCB*>::iterator it;
    int workComplete = 0, 
        process       = 0, 
        arrivalTime   = 0,
        burstTime     = 0,
        systemTime    = 0,
        wait_time     = 0,
        quantum       = q,
        count         = 0,
        difference    = 0,
        containerSize = v.size();
    while(!v.empty()) {
        struct timeval wait_start, wait_stop;
        wait_start.tv_usec = 0, wait_stop.tv_usec = 0;
        gettimeofday(&wait_start, NULL);

        process      = v[count]->getProcessID();
        arrivalTime  = v[count]->getArrivalTime();
        burstTime    = v[count]->getBurstSize();

        for (int i = 0; i < quantum; i++) {
            std::cout << "<system time " << systemTime << "> process " <<
               process << " is runnning" << std::endl;
            systemTime++;
            workComplete++;
        }

        difference = burstTime - workComplete;
        v[count]->setBurstSize(difference);

        gettimeofday(&wait_stop, NULL);
        wait_time = ((wait_stop.tv_sec - wait_start.tv_sec) * 1000000 +
            wait_stop.tv_usec - wait_start.tv_usec);

        count++;

        if (v[count]->getBurstSize() <= 0) {
            v.erase(v.begin()+count);
        }

        if (count >= containerSize-1)
            count = 0;
    }
    std::cout << "<system time " << systemTime << "> All processes " <<
       "finish...................." << std::endl;
    return wait_time;
}

#endif
