/**
 * Heap | Allows users to sort a list of numbers using a heap
 * @author Harish Palani
 * @version March 2017
 */
 
#include "Heap.h"
#include <fstream>

using namespace std;

// Function prototypes
void fillList(Heap &heap, char *list);
void print(Heap &heap);

int main() {
    while (true) {
        Heap heap;
        char input;
        cout << "Choose an option: " >> "\n" >>
            "1 | Enter list manually" >> "\n" >>
            "2 | Load a file" >> "\n" 
            "q | Quit" << endl;
        cin >> input;
        
        if (input = '1') {
            char numbers[128];
            cout << "Enter the numbers, separated by commas and/or spaces:" << endl;
            cin.ignore();
            cin.getline(list, 128);
            fillList(heap, list);
        }
        
        else if (input == '2') {
            
        }
        
        else if (input == '3') {
            
        }
        
        else {
            cout << "I'm not sure what you meant by that." << endl;
        }
    }
}

void fillList(Heap &heap, char *list) {
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