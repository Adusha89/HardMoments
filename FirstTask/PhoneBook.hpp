#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "PhoneNumber.hpp"
#include "Person.hpp"

class PhoneBook
{
private:
    std::vector<std::pair<Person, PhoneNumber>> m_book;

public:

    PhoneBook(std::ifstream&);
    ~PhoneBook() {}


    friend std::ostream& operator<< (std::ostream&, const PhoneBook&);
    void sortByName ();
    void sortByPhone ();
    const std::pair<std::string, PhoneNumber> getPhoneNumber(const std::string&) const;
    void changePhoneNumber (const Person&, const PhoneNumber&);
};


#endif