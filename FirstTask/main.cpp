#include <iostream>
#include "Person.hpp"
#include "PhoneNumber.hpp"



int main(int argc, char const *argv[])
{
    Person p{"Andrew", "Belyakov", "N"};
    Person p1{"Andrew", "Belyakov", "N"};
    std::cout << p << std::endl << p1 << std::endl;
   
    

    PhoneNumber ph{7,920,"1676166", 12};
    PhoneNumber ph1{7,920,"1676166", 12};

    if (ph == ph1)
    {
       std::cout << "Yes";
    }
    std::cout << ph << std::endl;

    return 0;
}
