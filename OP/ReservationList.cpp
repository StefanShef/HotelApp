#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <cmath>
#include <fstream>
#include "./ReservationList.h"

void ReservationList::printData() const
{
    cout.width(10);
    cout << m_typeOfRoom << "|";
    cout.width(10);
    cout << m_dateOfArrival << "|";
    cout.width(10);
    cout << m_dateOfDeparture << "|";
    cout.width(13);
    cout << m_numberOfSeats << "|";
    cout.width(13);
    cout << m_comments << "|";
    cout.width(9);
    cout << m_names[0] << "|";
    cout.width(9);
    cout << m_names[1] << "|";
    cout.width(9);
    cout << m_names[2] << "|";
    cout.width(17);
    cout << m_email << "|";
    cout.width(16);
    cout << m_phoneNumber << "|";
    cout.width(15);
    cout << m_paymentMethod << "|";
    cout.width(7);
    cout << m_price << "|";
}

ifstream &operator>>(ifstream &ifs, ReservationList &reserv)
{
    ifs >> reserv.m_typeOfRoom >> reserv.m_dateOfArrival >> reserv.m_dateOfDeparture >> reserv.m_numberOfSeats >> reserv.m_comments >> reserv.m_names[0] >> reserv.m_names[1] >> reserv.m_names[2] >> reserv.m_email >> reserv.m_phoneNumber >> reserv.m_paymentMethod >> reserv.m_price;
    return ifs;
}

ofstream &operator<<(ofstream &ofs, const ReservationList &reserv)
{
    ofs << reserv.m_typeOfRoom << " " << reserv.m_dateOfArrival << " " << reserv.m_dateOfDeparture << " " << reserv.m_numberOfSeats << " " << reserv.m_comments << " " << reserv.m_names[0] << " " << reserv.m_names[1] << " " << reserv.m_names[2] << " " << reserv.m_email << " " << reserv.m_phoneNumber << " " << reserv.m_paymentMethod << " " << reserv.m_price << endl;
    return ofs;
}

ReservationList::ReservationList(string _typeOfRoom, string _dateOfArrival, string _dateOfDeparture, string _numberOfSeats, string _comments, string _surname, string _name, string _secondName, string _email, string _phoneNumber, string _paymentMethod, string _price){
    m_typeOfRoom = _typeOfRoom;
    m_dateOfArrival = _dateOfArrival;
    m_dateOfDeparture = _dateOfDeparture;
    m_numberOfSeats = _numberOfSeats;
    m_comments = _comments;
    m_names[0] = _surname;
    m_names[1] = _name;
    m_names[2] = _secondName;
    m_email = _email;
    m_phoneNumber = _phoneNumber;
    m_paymentMethod = _paymentMethod;
    m_price = _price;

}

ReservationList::ReservationList(){}
