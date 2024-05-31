#pragma once
#include <iostream>
#include <string>
using namespace std;
class User
{
protected:

public:
    virtual void printData() const = 0;
    string m_typeOfRoom{"-"};
    string m_numberOfSeats{"-"};
    string m_comments{"-"};
    string m_names[3]{"-", "-", "-"};
    string m_email{"-"};
    string m_phoneNumber{"-"};
    string m_paymentMethod{"-"};
    string m_dateOfArrival = "-";   // публичные, чтобы обратиться в сортировке
    string m_dateOfDeparture = "-"; // по факту нужно это делать через геттер
};
