#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include "pCout.hpp"
#include "ownerAndThief.hpp"

int main(int argc, char const *argv[])
{
    firstTask();
    addAndPop();
    return 0;
}
