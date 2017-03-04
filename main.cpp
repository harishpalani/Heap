/**
 * Heap | Allows users to sort a list of numbers using a heap
 * @author Harish Palani
 * @version March 2017
 */
 
#include "Heap.h"
#include <fstream>

using namespace std;

// Function prototypes
void fillHeap(Heap &heap, char *list);
void print(Heap &heap);

int main() {
    while (true) {
        Heap heap;
        char input;
        cout << "Choose an option: \n- 1 | Enter list manually \n- 2 | Load a file \n- q | Quit" << endl;
        cin >> input;
        char numbers[128];
        
        if (input == '1') {
            cout << "Please enter your list:" << endl;
            cin.ignore();
            cin.getline(numbers, 128);
            fillHeap(heap, numbers);
        } else if (input == '2') {
            char filename[64];
            cout << "Please enter the filename: " >> endl;
            cin >> filename;
            
            ifstream stream(filename);
            if (stream.is_open()) {
                stream.getline(numbers, 128, 0);
                stream.close();
                fillHeap(heap, numbers);
            } else {
                cout << "Error: File not found" << endl;
                continue;
            }
        }
        
        else if (input == 'q') {
            
        }
        
        else {
            cout << "I'm not sure what you meant by that." << endl;
        }
    }
}

void fillHeap(Heap &heap, char *list) {
    int i = 0;
    while(list[i]) {
        if(isdigit(list[i])) {
            int n = list[i] - '0';
            while(isdigit(list[++i])) {
                n = 10*n + (list[i] - '0');
            }
            heap.insert(n);
        } else {
            i++;
        }
    }
}

void print(Heap &heap) {
    cout << heap.pop();
    while(!heap.isEmpty()){
        cout << ", " << heap.pop();
    }
    cout << "." << endl;
}