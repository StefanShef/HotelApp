#include "Iterator.h"
#include <iostream>
using namespace std;
Iterator::Iterator(const Iterator& it) : m_reservatonList(it.m_reservatonList) {}
bool Iterator::operator==(const Iterator& it) const {
return m_reservatonList == it.m_reservatonList;
}
bool Iterator::operator!=(const Iterator& it) const {
return m_reservatonList != it.m_reservatonList;
}
Iterator& Iterator::operator++() {
m_reservatonList++;
return *this;
}
ReservationList& Iterator::operator*() const {
return *m_reservatonList;
}
