cmake_minimum_required(VERSION 3.25)
project(BankAccountManagement_CPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(BankAccountManagement_CPP main.cpp account.cpp account.h date.cpp date.h)
