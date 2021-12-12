#ifndef OWNERANDTHIEF_HPP
#define OWNERANDTHIEF_HPP

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <ctime>
#include <algorithm>

std::vector<int> things;

void owner()
{
    
    things.push_back(rand()%100+1);
    std::cout << "Owner add a: " << *(things.end()-1) << std::endl;
}

void thief()
{
    auto del = std::max_element(things.begin(), things.end());
    std::cout << "Thief stole a: " << *del << std::endl;
    things.erase(del);
    
}

void addAndPop()
{
    srand(time(NULL));
    std::thread o(owner);
    std::thread t(thief);
    o.join();
    t.join();
}
#endif