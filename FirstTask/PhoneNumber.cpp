#include "PhoneNumber.hpp"

std::ostream& operator<< (std::ostream& out , const PhoneNumber& number)
{
    out << "+" << number.countryCode << "(" << number.cityCode << ")"
        << number.number;

    if(number.addNumber)
    {
        out << " " << number.addNumber.value();
    }
    return out;
}

bool operator< (const PhoneNumber& ph1 , const PhoneNumber& ph2)
{
    return std::tie(ph1.countryCode, ph1.cityCode, ph1.number, ph1.addNumber)
        < std::tie(ph2.countryCode, ph2.cityCode, ph2.number, ph2.addNumber);
}

bool operator== (const PhoneNumber& ph1 , const PhoneNumber& ph2)
{
    return std::tie(ph1.countryCode, ph1.cityCode, ph1.number, ph1.addNumber)
        == std::tie(ph2.countryCode, ph2.cityCode, ph2.number, ph2.addNumber);
}