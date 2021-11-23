#include "Person.hpp"

std::ostream& operator<< (std::ostream& out, const Person& person)
{
    out << std::setw(15) << std::right << person.surname
         << "   " << std::setw(15) << std::right << person.name << "   "
            << std::setw(15) << std::right << person.patronymic.value_or("");
    
    return out;
}

bool operator< (const Person& person1, const Person& person2)
{
    return std::tie(person1.surname, person1.name, person1.patronymic) 
        < std::tie(person2.surname, person2.name, person2.patronymic);
}

bool operator== (const Person& person1, const Person& person2)
{
    return std::tie(person1.surname, person1.name, person1.patronymic) 
        == std::tie(person2.surname, person2.name, person2.patronymic);
}