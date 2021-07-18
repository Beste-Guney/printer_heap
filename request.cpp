/*
* Title: Heaps
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 3
* Description: This is the implementation file for request
*/
#include <iostream>
#include "request.h"
using namespace std;

Request::Request(){
    id = 0;
    priority = 0;
    requestTime = 0;
    processTime = 0;
}

Request::Request(int id1, int pri, int req, int pro){
    id = id1;
    priority = pri;
    requestTime = req;
    processTime = pro;
}

int Request::getId(){
    return id;
}

int Request::getPriority(){
    return priority;
}

int Request::getProcessTime(){
    return processTime;
}

int Request::getRequestTime(){
    return requestTime;
}

void Request::setId(int value){
    id = value;
}

void Request::setPriority(int value){
    priority = value;
}

void Request::setProcessTime(int value){
    processTime = value;
}

void Request::setRequestTime(int value){
    requestTime = value;
}
