/*
* Title: Heaps
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 3
* Description: This is the header file for requests
*/
#include <iostream>
using namespace std;

class Request{
public:
    Request();
    Request(int, int, int, int);
    //~Request();

    int getId();
    int getPriority();
    int getRequestTime();
    int getProcessTime();

    void setId(int);
    void setPriority(int);
    void setRequestTime(int);
    void setProcessTime(int);
private:
    int requestTime;
    int priority;
    int id;
    int processTime;
};
