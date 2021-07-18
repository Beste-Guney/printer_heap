/*
* Title: Heaps
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 3
* Description: This is the header file for heap
*/
#include "request.h"
const int MAX_SIZE = 100;

class Heap{
public:
    Heap();
    //~Heap();

    bool isEmpty();
    void insertItem(Request item);
    void deleteItem(Request& item);
    void printHeap();

private:
    void heapRebuild(int index);
    Request maxHeap[MAX_SIZE];
    int size;
};
