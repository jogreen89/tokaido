#include <stdio.h>

#include "pcb.h"

int main(int argc, char **argv) {
    printf("Hello, World.\n");
    PCB *p = new PCB();
    printf("%d\n", p->getProcessNumber());
}
