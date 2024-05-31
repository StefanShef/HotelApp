#pragma once
#include "./ReservationList.h"

class Iterator {
    friend class MyVector;
public:
    Iterator(const Iterator&);
    bool operator==(const Iterator&) const;
    bool operator!=(const Iterator&) const;
    Iterator& operator++();
    ReservationList& operator*() const;
private:
    ReservationList* m_reservatonList;
    Iterator(ReservationList* p) : m_reservatonList(p) {}
};
