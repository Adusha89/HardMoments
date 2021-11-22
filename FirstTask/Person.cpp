#include "Person.hpp"

std::ostream& operator<< (std::ostream& out, const Person& person)
{
    out << std::setw(10) << std::right << person.name
         << "   " << std::setw(10) << std::right << person.surname 
            << std::setw(10) << std::right << person.patronymic.value_or("");
    
    return out;
}

bool operator< (const Person& p1, const Person& p2)
{
    return std::tie(p1.name, p1.surname, p1.patronymic) 
        < std::tie(p2.name, p2.surname, p2.patronymic);
}

bool operator== (const Person& p1, const Person& p2)
{
    return std::tie(p1.name, p1.surname, p1.patronymic) 
        == std::tie(p2.name, p2.surname, p2.patronymic);
}