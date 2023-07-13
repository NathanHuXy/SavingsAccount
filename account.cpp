//
// Created by Yan Yan on 2023/7/13.
//

#include "account.h"
#include <iostream>
#include <cmath>

using namespace std;

double SavingsAccount::total = 0;

void SavingsAccount::record(const Date &date, double amount, const std::string &desc) {
    accumulation = this->accumulate(date);
    lastDate = date;
    amount = floor(amount*100+0.5)/100;
    balance += amount;
    date.show();
    cout <<  "#" << id << "\tAccount change: " << amount << "\t Balance: "<< balance<< '\t' << desc << endl;
}

SavingsAccount::SavingsAccount(const std::string& newId, const Date &newDate, double newRate): lastDate(newDate) {
    id = newId;
    rate = newRate;
    balance=0;
    accumulation=0;
    newDate.show();
    cout << "\t#" << id << " is created."<<endl;
}

void SavingsAccount::deposit(const Date &date, double amount, const std::string &desc) {
    this->record(date, amount,desc);
}

void SavingsAccount::withdraw(const Date &date, double amount, const std::string &desc){
    if (amount > this->getBalance()){
        cout << "ERROR: Without enough money!"<<endl;
    }else{
        this->record(date, -amount,desc);
    }

}

void SavingsAccount::settle(const Date &date) {
    double interest = accumulate(date)*rate/365;
    if (interest!=0){
        record(date, interest, "interest");
    }
    accumulation=0;
}

void SavingsAccount::showAccount() const {
    cout << "#" << id << "\t Balance: "<< balance<<endl;
}

void SavingsAccount::error(const string &desc) {
    cout << "ERROR(#" << id << "): "<<desc<<endl;
}
