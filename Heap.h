#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class Heap {
    public:
        Heap();
        ~Heap();
        
    private:
        int count;
        int size;
        int *nodes;
}

#endif