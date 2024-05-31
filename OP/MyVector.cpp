#include "MyVector.h"
#include <iostream>
using namespace std;
MyVector::MyVector()
{
    m_array = new ReservationList[1];
    m_size = 0;
    m_capacity = 1;
}
MyVector::iterator MyVector::begin()
{
    return iterator(m_array);
}
MyVector::iterator MyVector::end()
{
    return iterator(m_array + m_size);
}
MyVector::const_iterator MyVector::begin() const
{
    return const_iterator(m_array);
}
MyVector::const_iterator MyVector::end() const
{
    return const_iterator(m_array + m_size);
}
size_t MyVector::Size()
{
    return m_size;
}
void MyVector::AddMemory()
{
    m_capacity *= 2;
    ReservationList *tmp = m_array;
    m_array = new ReservationList[m_capacity];
    for (size_t i = 0; i < m_size; i++)
    {
        m_array[i] = tmp[i];
    }
    delete[] tmp;
}
void MyVector::PushBack(const ReservationList &value)
{
    if (m_size >= m_capacity)
    {
        AddMemory();
    }
    m_array[m_size] = value;
    m_size++;
}
void MyVector::Remove(size_t index)
{
    for (size_t i = index + 1; i < m_size; ++i)
    {
        m_array[i - 1] = m_array[i];
    }
    m_size--;
}

ReservationList &MyVector::operator[](int i)
{
    return m_array[i];
}
