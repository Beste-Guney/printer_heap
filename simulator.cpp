/*
* Title: Heaps
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 3
* Description: This is the implementation file for simulator
*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "simulator.h"
using namespace std;

Simulator::Simulator(const char* arg, double time){
    waitingTime = time;
    totalProcessTime = 0;
    totalRequestTime = 0;
    if(arg != NULL){
        takeRequest(arg);
    }
}

void Simulator::takeRequest(const char* arg){
//fstream to open the file
    ifstream file;
    file.open(arg);
    int lineNumber = 0;

    if(file.is_open()){
        string line;

        while(getline(file, line)){
            if(lineNumber == 0){
                stringstream str(line);
                str >> numberOfRequests;
                requests = new Request[numberOfRequests];
            }
            else{
                int index = 0;
                string idValue = "";
                for(int i = 0; i < line.length(); i++){
                    if(line[i] == ' '){
                        index = i;
                        break;
                    }
                    idValue = idValue + line[i];
                }
                stringstream str(idValue);
                int id;
                str >> id;

                string prio = "";
                for(int i = index+1; i < line.length(); i++){
                    if(line[i] == ' '){
                        index = i;
                        break;
                    }
                    prio = prio + line[i];
                }
                stringstream str2(prio);
                int priority;
                str2 >> priority;

                string req = "";
                for(int i = index+1; i < line.length(); i++){
                    if(line[i] == ' '){
                        index = i;
                        break;
                    }
                    req = req + line[i];
                }
                stringstream str3(req);
                int request;
                str3 >> request;

                string pro;
                for(int i = index+1; i < line.length(); i++){
                    if(line[i] == '\n')
                        break;
                    pro = pro + line[i];
                }
                stringstream str4(pro);
                int process;
                str4 >> process;

                Request r1(id,priority,request,process);
                totalProcessTime = totalProcessTime + process;
                totalRequestTime = totalRequestTime + request;
                requests[lineNumber-1] = r1;
            }
            lineNumber++;
        }
        file.close();
    }

}
void Simulator::printRequests(){
    for(int i = 0; i < numberOfRequests; i++)
        cout << requests[i].getId() << " " << requests[i].getPriority() << " " << requests[i].getRequestTime() << " " << requests[i].getProcessTime() << endl;
}

double Simulator::averageForPrinter(int printerNumber){
    Heap* process = new Heap;
    Printer* printers = new Printer[printerNumber];
    int waitTime = 0;
    for(int i = 0; i < printerNumber; i++){
        printers[i].setId(i);
    }

    for(int i = 1; i <= totalProcessTime + totalRequestTime; i++){
        for(int j = 0; j < numberOfRequests; j++){
            if(requests[j].getRequestTime() == i){
                process->insertItem(requests[j]);
            }
        }

        for(int j = 0; j < printerNumber; j++){
            if(printers[j].getAvailable(i) && !process->isEmpty()){
                Request temp;
                process->deleteItem(temp);
                printers[j].setProcess(temp.getProcessTime());
                printers[j].addTotalProcess(temp.getProcessTime());
                waitTime = waitTime + (i - temp.getRequestTime());
            }
        }
    }
    delete process;
    delete []printers;
    return ((double)waitTime / (double)numberOfRequests);
}

void Simulator::printSimulation(int printerNumber){
    cout << "Simulation with " << printerNumber << " printers:" << endl;
    Heap* process = new Heap;
    Printer* printers = new Printer[printerNumber];
    int waitTime = 0;
    for(int i = 0; i < printerNumber; i++){
        printers[i].setId(i);
    }

    for(int i = 1; i <= totalProcessTime + totalRequestTime; i++){
        for(int j = 0; j < numberOfRequests; j++){
            if(requests[j].getRequestTime() == i){
                process->insertItem(requests[j]);
            }
        }

        for(int j = 0; j < printerNumber; j++){
            if(printers[j].getAvailable(i) && !process->isEmpty()){
                Request temp;
                process->deleteItem(temp);
                printers[j].setProcess(temp.getProcessTime());
                printers[j].addTotalProcess(temp.getProcessTime());
                cout << "Printer " << j << " print request " << temp.getId() << " at minute " << i << " (wait : " << i - temp.getRequestTime() << " )" << endl;
                waitTime = waitTime + (i - temp.getRequestTime());
            }
        }
    }
    cout << "Average waiting time: " << averageForPrinter(printerNumber) << endl;
    delete process;
    delete []printers;
}
int Simulator::findLeastNumberOfPrinters(){
    int minPrinter = 0;
    int minTime = 0;

    for(int i = 1; i <= numberOfRequests; i++){
        double time = averageForPrinter(i);
        if(time <= waitingTime){
            minPrinter = i;
            i = numberOfRequests + 1;
        }
    }
    return minPrinter;
}
