/*
* Title: Heaps
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 3
* Description: This is the implementation file for printer
*/
#include <iostream>
#include "printer.h"
using namespace std;

Printer::Printer(){
    id = 0;
    lastProcess = 0;
    lastRequest = 0;
    totalProcess = 0;
    isAvaiable = true;
}

Printer::Printer(int value){
    id = value;
    lastProcess = 0;
    lastRequest = 0;
    totalProcess = 0;
    isAvaiable = true;
}

int Printer::getId(){
    return id;
}

void Printer::setAvailable(bool ava){
    isAvaiable = ava;
}

bool Printer::getAvailable(int request){
    if(request > totalProcess)
        return true;
    else{
        return false;
    }
}

int Printer::getLastProcessTime(){
    return lastProcess;
}

int Printer::getLastRequestTime(){
    return lastRequest;
}
void Printer::setId(int value){
    id = value;
}

void Printer::setProcess(int pro){
    lastProcess = pro;
}

void Printer::setRequest(int req){
    lastRequest = req;
}

void Printer::addTotalProcess(int total){
    totalProcess += total;
}

int Printer::getTotalProcess(){
    return totalProcess;
}
