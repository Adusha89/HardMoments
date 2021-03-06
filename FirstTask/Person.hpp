#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <optional>
#include <iomanip>
#include <tuple>

struct Person
{
    std::string surname;
    std::string name;
    std::optional<std::string> patronymic = std::nullopt;

};

std::ostream& operator<< (std::ostream& , const Person& );
bool operator< (const Person& , const Person& );
bool operator== (const Person& , const Person& );

#endif