#include "Date.hpp"

bool t_date::operator<(const s_date &date) const {
    if (date.year < this->year)
        return true;
    if (date.month < this->month)
        return true;
    if (date.day < this->month)
        return true;
    return false;
}