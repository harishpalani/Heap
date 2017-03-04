#include <iostream>
#include <cstring>
#include <cmath>
#include "Heap.h"

using namespace std;

Heap::Heap() {
    count = 0;
    size = 128;
    nodes = new int[size];
    memset(nodes, 0, sizeof(nodes)); // Use memset to fill node array with 0
}

Heap::~Heap() {
    delete[] nodes;
}

bool Heap::isEmpty() {
    return nodes[0] == 0;
}

int Heap::peek() {
    return nodes[0];
}

int Heap::pop() {
    int top = nodes[0];
    nodes[0] = nodes[count - 1];
    nodes[count - 1] = 0;
    count--;
    recursiveDown(0);
    return top;
}

void Heap::insert(int n) {
    
}

void Heap::print() {
    
}

void Heap::recursiveUp(int n) {
    if (n <= 0) { return; }
    
    int p = (n - 2)/2;
    if (n % 2 == 1) {
        p = (n - 1)/2;
    }
    
    if (nodes[n] > nodes[p]) {
        int temp = nodes[p];
        nodes[p] = nodes[n];
        nodes[n] = temp;
        recursiveUp(p);
    }
}

void Heap::recursiveDown(int n) {
    if(nodes[n] < nodes[2*n + 1] || nodes[n] < nodes[2*n + 2]) {
        int max = 2*n + 2;
        
        if (nodes[2*n + 1] > nodes[2*n + 2]) {
            max = 2*n + 1;
        }
        
        int temp = nodes[n];
        nodes[n] = nodes[max];
        nodes[max] = temp;
        recursiveDown(max);
    }
}