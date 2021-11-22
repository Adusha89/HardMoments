#ifndef PHONENUMBER_HPP
#define PHONENUMBER_HPP

#include <iostream>
#include <optional>
#include <iomanip>
#include <tuple>

struct PhoneNumber
{
    int countryCode;
    int cityCode;
    std::string number;
    std::optional<int> addNumber = std::nullopt;
};

std::ostream& operator<< (std::ostream& , const PhoneNumber& );
bool operator< (const PhoneNumber& , const PhoneNumber& );
bool operator== (const PhoneNumber& , const PhoneNumber& );

#endif