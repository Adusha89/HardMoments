#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

class PhoneBook
{
private:
    std::vector<std::pair<Person, PhoneNumber>> m_book;

public:

    PhoneBook(std::ifstream& fin)
    {
        Person person;
        PhoneNumber phoneNumber;
        std::string tempString;
        while (!fin.eof())
        {
            fin >> tempString;
            person.surname = tempString;
            fin >> tempString;
            person.name = tempString;
            fin >> tempString;
            if (tempString == "-")
            {
                person.patronymic = std::nullopt;
            }
            else
            {
                person.patronymic = tempString;
            }
            fin >> tempString;
            phoneNumber.countryCode = atoi(tempString.c_str());
            fin >> tempString;
            phoneNumber.cityCode = atoi(tempString.c_str());
            fin >> tempString;
            phoneNumber.number = tempString;
            fin >> tempString;
            if (tempString == "-")
            {
                phoneNumber.addNumber = std::nullopt;
            }
            else
            {
                phoneNumber.addNumber = atoi(tempString.c_str());
            }

            m_book.push_back(std::make_pair(person, phoneNumber));

        }
        fin.close();
    }

    ~PhoneBook() {}


    friend std::ostream& operator<< (std::ostream&, const PhoneBook&);
    void sortByName ();
    void sortByPhone ();
    const std::pair<std::string, PhoneNumber> getPhoneNumber(const std::string&);
};

std::ostream& operator<< (std::ostream& out, const PhoneBook& phoneBook) 
{
    for (const auto [person, phoneNumber] : phoneBook.m_book)
    {
        out << person << "  " << phoneNumber << std::endl;
    }

    return out;
}

void PhoneBook::sortByName ()
{
    std::sort (m_book.begin(), m_book.end(), [](std::pair<Person, PhoneNumber> person1, std::pair<Person, PhoneNumber> person2)
        { return person1.first < person2.first; });
}

void PhoneBook::sortByPhone ()
{
    std::sort (m_book.begin(), m_book.end(), [](std::pair<Person, PhoneNumber> person1, std::pair<Person, PhoneNumber> person2)
    {return person1.second < person2.second;});
}

const std::pair<std::string, PhoneNumber> PhoneBook::getPhoneNumber (const std::string& surname)
{
    size_t count = 0;
    std::pair<std::string, PhoneNumber> tempPair;
    PhoneNumber tempPhone;

    for (const auto& [person, phoneNumber] : m_book )
    {
        if (person.surname == surname)
        {
            ++count;
            tempPhone = phoneNumber;
        }
    }
    if (!count)
    {
        return std::make_pair("Not Found", PhoneNumber());
    }
    if (count == 1)
    {
        return std::make_pair("", tempPhone);
    }

    return std::make_pair("found more then 1", tempPhone);
}

#endif