/*
* Title: Heaps
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 3
* Description: This is the main file for simulator
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include "simulator.h"
using namespace std;
int main(int arg, char* avg[]){
    if(avg != NULL ){
       string ave = avg[arg-1];
        stringstream str(ave);
        double average = 0;
        str >> average;

        Simulator sim(avg[1],average);
        int minPrinter = 0;
        minPrinter = sim.findLeastNumberOfPrinters();
        cout << "Minimum number of printers required: " << minPrinter << endl;
        sim.printSimulation(minPrinter);
    }

}
