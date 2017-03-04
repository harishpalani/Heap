#include <iostream>
#include <cstring>
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