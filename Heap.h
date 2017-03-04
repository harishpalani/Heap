#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class Heap {
    public:
        Heap();
        ~Heap();
        int peek();
        int pop();
        bool isEmpty();
        void insert(int n);
        void print();
        void recursiveUp(int i);
        void recursiveDown(int i);
        
    private:
        int count;
        int size;
        int *nodes;
};

#endif