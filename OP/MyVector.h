#pragma once
#include "Iterator.h"
#include "./ReservationList.cpp"
class MyVector
{
public:
    typedef Iterator iterator;
    typedef Iterator const_iterator;
    MyVector();
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    void AddMemory();
    void PushBack(const ReservationList &);
    void Remove(size_t);
    size_t Size();
    ReservationList &operator[](int i);

private:
    ReservationList *m_array{};
    size_t m_size{};
    size_t m_capacity{};
};
