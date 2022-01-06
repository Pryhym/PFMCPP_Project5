#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct Server
    {
        std::string name = "James";
        long phoneNum = 8434305954;
        int amOfPeopleServed;
        float hoursWorked;
       
        Server():
        amOfPeopleServed(8),
        hoursWorked(17.5f){}
        ~Server(){}

        float currPay = 9.45f;
        void serveCustomer();
        void cleanTable();
        float countTip(float tip);
    };
   
   











