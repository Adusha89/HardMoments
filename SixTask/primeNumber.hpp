#ifndef PRIMENUMBER_HPP
#define PRIMENUMBER_HPP

#include <iostream>
#include <math.h>

bool isPrime(uint number)
{
    int border = sqrt(number);
    for (size_t idx = 2; idx <= border; ++idx)
    {
        if (number%idx == 0)
            return false;

    }
    return true;
}

uint findPrime(uint serialNumber)
{
    if (serialNumber == 1)
        return 2;
    if (serialNumber == 2)
        return 3;
    if (serialNumber == 3)
        return 5;   
    uint count = 3;
    uint number = 5;
    while (count != serialNumber)
    {
       ++number;
       if (isPrime(number))
       {
           ++count;
           std::cout << "Progress: " << (static_cast<double>(count)/serialNumber)*100. << "%" << std::endl;
       }
       
       
    }
    return number;
}

#endif