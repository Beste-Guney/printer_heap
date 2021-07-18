/*
* Title: Heaps
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 3
* Description: This is the implementation file for heap
*/
#include <iostream>
#include "heap.h"
using namespace std;

Heap::Heap(){
    size = 0;
}

bool Heap::isEmpty(){
    return size == 0;
}

void Heap::insertItem(Request item){
    if(size >= MAX_SIZE)
        return;

    maxHeap[size] = item;

    int place = size;
    int parent = (place-1)/2;
    while(place > 0 && maxHeap[place].getPriority() > maxHeap[parent].getPriority()){
        Request temp = maxHeap[place];
        maxHeap[place] = maxHeap[parent];
        maxHeap[parent] = temp;

        place = parent;
        parent = ( place-1)/2;
    }
    size++;
}

void Heap::deleteItem(Request& item){
    if(size <= 0 )
        return;
    else{
        item = maxHeap[0];
        size = size -1;
        maxHeap[0] = maxHeap[size];
        heapRebuild(0);
    }
}

void Heap::heapRebuild(int index){
    int child = index * 2 + 1;

    if(child < size){
        int other = child +1;
        if(other < size && (maxHeap[other].getPriority() > maxHeap[child].getPriority())){
                child = other;
        }
        else if (other < size && (maxHeap[other].getPriority() == maxHeap[child].getPriority())){
            if(maxHeap[other].getRequestTime() < maxHeap[child].getRequestTime()){
                child = other;
            }
        }

    if(maxHeap[index].getPriority() < maxHeap[child].getPriority() || ((maxHeap[index].getPriority() == maxHeap[index].getPriority()) && maxHeap[index].getRequestTime() > maxHeap[child].getRequestTime()))
    {
        Request temp = maxHeap[index];
        maxHeap[index] = maxHeap[child];
        maxHeap[child] = temp;

        heapRebuild(child);
    }
    }
}

void Heap::printHeap(){
    int index = 0;
    while(index < size){
        cout << maxHeap[index].getId() << " " << maxHeap[index].getPriority() <<" " << maxHeap[index].getRequestTime() <<" " << maxHeap[index].getProcessTime();
        index++;
        cout << endl;
    }
    cout << endl;
}
