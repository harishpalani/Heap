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
        cout << "\nChoose an option: \n1 | Enter list manually \n2 | Load a file \nq | Quit" << endl;
        cin >> input;
        char numbers[128];
        
        // Load heap for manual list entry
        if (input == '1') {
            cout << "\nPlease enter your list:" << endl;
            cin.ignore();
            cin.getline(numbers, 128);
            fillHeap(heap, numbers);
        } 
        
        // Load heap for file-based list entry
        else if (input == '2') {
            char filename[64];
            cout << "\nPlease enter the filename: " << endl;
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
        } else if (input == 'q') {
            break;  
        } else {
            cout << "I'm not sure what you meant by that." << endl;
        }
        
        cout << "\nChoose an option: \n1 | Print out list\n2 | Print out tree\n3 | Do both!\nq | Quit" << endl;
        cin >> input;
        
        // Print just the list (in descending order)
        if (input == '1') {
            cout << endl;
            print(heap);
            cout << endl;
        } 
        
        // Print just the tree
        else if (input == '2') {
            cout << endl;
            heap.printTree();
        } 
        
        // Print both the list and the tree
        else if (input == '3') {
            cout << endl;
            heap.printTree();
            cout << endl;
            print(heap);
            cout << endl;
        } else if (input == 'q') {
            break;  
        } else {
            cout << "I'm not sure what you meant by that." << endl;
        }
        
        // Do it again? (y/n)
        cout << "\ny/n | Do you have another list in mind? ";
        cin >> input;
        if (input != 'y') { break; }
    }
}

// Populate the heap with the list
void fillHeap(Heap &heap, char *list) {
    int i = 0;
    while (list[i]) {
        if (isdigit(list[i])) {
            int n = list[i] - '0';
            while (isdigit(list[++i])) {
                n = 10*n + (list[i] - '0');
            }
            heap.insert(n);
        } else {
            i++;
        }
    }
}

// Print the heap contents in the form of a list
void print(Heap &heap) {
    cout << heap.pop();
    while (!heap.isEmpty()) {
        cout << ", " << heap.pop();
    }
}