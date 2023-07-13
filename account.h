//
// Created by Yan Yan on 2023/7/13.
//

#ifndef BANKACCOUNTMANAGEMENT_CPP_ACCOUNT_H
#define BANKACCOUNTMANAGEMENT_CPP_ACCOUNT_H

#include "date.h"
#include <iostream>

class SavingsAccount{
private:
    std::string id;
    double balance;
    double rate;
    Date lastDate;
    double accumulation;
    void record(const Date &date, double amount, const std::string &desc);
    void error(const std::string &desc);

    [[nodiscard]] double accumulate(const Date& date) const{
        return accumulation + balance*date.distance(lastDate);
    }
    static double total;
public:
    SavingsAccount(const std::string& newId, const Date &newDate, double newRate);
    [[nodiscard]] const std::string getId() const {
        return id;
    }
    [[nodiscard]] double getBalance() const{
        return balance;
    }

    [[nodiscard]] double getRate() const{
        return rate;
    }
    void deposit(const Date &date, double amount, const std::string &desc);
    void withdraw(const Date &date, double amount,const std::string &desc);
    void settle(const Date &date);
    void showAccount() const;
    static double getTotal(){return total;}

};


#endif //BANKACCOUNTMANAGEMENT_CPP_ACCOUNT_H
