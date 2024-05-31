#pragma once
#include <iostream>
#include <string>
#include "user.h"
#include <fstream>
using namespace std;

class ReservationList : public User{
public:
    string m_price{"-"}; //Надо прописать функцию, которая будет высчитывать прайс
    void printData() const;
    friend ifstream& operator >> (ifstream& ifs, ReservationList& reserv); //перегрузка ввода из файла
    friend ofstream &operator<<(ofstream &ofs, const ReservationList &reserv);        // перегрузка вывода в файл
    ReservationList(string, string , string, string , string , string , string ,string , string , string , string , string);
    ReservationList(); 
};
