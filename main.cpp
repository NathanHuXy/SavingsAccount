#include "account.h"
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    Date date(2001,12,31);
    SavingsAccount sa("Xueyan Hu",date, 0.015);
    sa.deposit(Date(2002,2,28),5000,"salary1");
    sa.deposit(Date(2002,6,30),5000,"salary2");
    sa.withdraw(Date(2002,9,15),4000,"by a laptop");
    sa.settle(Date(2002,12,31));
    sa.showAccount();
    return 0;
}