/*
* Title: Heaps
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 3
* Description: This is the header file for printer
*/
#include <iostream>
using namespace std;

class Printer{
public:
    Printer();
    Printer(int);

    //~Printer();

    int getId();
    int getLastProcessTime();
    int getLastRequestTime();
    int getTotalProcess();
    bool getAvailable(int);

    void setId(int);
    void setRequest(int);
    void setProcess(int);
    void addTotalProcess(int);
    void setAvailable(bool);

private:
    int id;
    int lastRequest;
    int lastProcess;
    int totalProcess;
    bool isAvaiable;
};
