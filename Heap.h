#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstring>
#include <cmath>

class Heap {
    public:
        Heap();
        ~Heap();
        int peek();
        int pop();
        void insert(int n);
        void printTree();
        void recursiveUp(int i);
        void recursiveDown(int i);
        bool isEmpty();
        
    private:
        int count;
        int size;
        int *nodes;
};

#endif