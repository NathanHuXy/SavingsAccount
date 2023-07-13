//
// Created by Yan Yan on 2023/7/13.
//

#ifndef BANKACCOUNTMANAGEMENT_CPP_DATE_H
#define BANKACCOUNTMANAGEMENT_CPP_DATE_H


class Date {
private:
    int year,month,day;
    int totalDays;
public:
    Date(int newYear, int newMonth, int newDay);
    [[nodiscard]] int getYear() const{
        return year;
    }
    [[nodiscard]] int getMonth() const{
        return month;
    }
    [[nodiscard]] int getDay() const{
        return day;
    }
    [[nodiscard]] bool isLeapYear() const {
        return year%4==0 && year%100!=0 || year%400==0;
    }
    int getMaxDay() const;
    void show() const;
    int distance(const Date &date) const{
        return totalDays - date.totalDays;
    }
};
#endif //BANKACCOUNTMANAGEMENT_CPP_DATE_H
