/*
* Title: Heaps
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 3
* Description: This is the header file for simulator
*/
#include <iostream>
#include "heap.h"
#include "printer.h"
using namespace std;

class Simulator{
public:
    Simulator(const char*, double time);

    void takeRequest(const char*);
    void printRequests();

    //return average time for number of printer
    double averageForPrinter(int);
    int findLeastNumberOfPrinters();
    void printSimulation(int);
private:
    int numberOfRequests;
    double waitingTime;
    int totalProcessTime;
    int totalRequestTime;
    Request* requests;
};
