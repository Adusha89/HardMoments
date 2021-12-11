#ifndef OWNERANDTHIEF_HPP
#define OWNERANDTHIEF_HPP

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <ctime>


void ownerAndThief ()
{
    srand(time(NULL));
    std::vector<int> things;
    std::thread owner([&]()
    {
            things.push_back(rand()%100+1);
            for (const auto& t : things)
            {
                std::cout << t << " ";
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        
    });
    owner.join();
}

#endif