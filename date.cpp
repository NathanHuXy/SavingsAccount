//
// Created by Yan Yan on 2023/7/13.
//

#include "date.h"
#include <iostream>

using namespace std;

namespace {
    const int DAYS_BEFORE_MONTH[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
}


Date::Date(int newYear, int newMonth, int newDay): year(newYear),month(newMonth),day(newDay){
    if (day<=0 || day>getMaxDay()){
        cout << "Invalid date: ";
        show();
        cout << endl;
        exit(1);
    }
    int years = year-1;
    totalDays = years*365+years/4-years/100+years/400+DAYS_BEFORE_MONTH[month-1]+day;
    if (isLeapYear() && month > 2){totalDays++;}
}

int Date::getMaxDay() const {
    if (isLeapYear() && month > 2){
        return 29;
    }else{
        return DAYS_BEFORE_MONTH[month]-DAYS_BEFORE_MONTH[month-1];
    }
}

void Date::show() const {
    cout << getYear() <<"-" << getMonth() <<"-" << getDay();
}




