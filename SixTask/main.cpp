#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include "pCout.hpp"
#include "ownerAndThief.hpp"
#include "primeNumber.hpp"

int main(int argc, char const *argv[])
{
    firstTask();
    //addAndPop();
    /* std::thread th([]()
        {
            std::cout << findPrime(10000) << std::endl;
        });
    th.join(); */
    return 0;
}
