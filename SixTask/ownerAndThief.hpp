#ifndef OWNERANDTHIEF_HPP
#define OWNERANDTHIEF_HPP

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <ctime>
#include <algorithm>


class Things
{
private:
    std::vector<int> things = {88,55,21,7,14,56,41,74,58,65};
    std::mutex m;

public:
    Things()
    {

    }
    void addEl(int el)
    {
        std::lock_guard<std::mutex> lock(m);
        things.push_back(el);
    }

    void stoleEl()
    {
        things.erase(std::max_element(things.begin(), things.end()));
    }

    void printThings()
    {
        std::lock_guard<std::mutex> lock(m);
        for (const auto& t : things)
        {
            std::cout << t << " ";
        }
    }

    bool isEmlpty() const
    {
        return things.empty();
    }
};



void owner(Things& things)
{
    while(true)
    {
        if (things.isEmlpty())
            break;
        things.printThings();
        things.addEl(rand()%100+1);
        
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
    }
    
}

void thief(Things& things)
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        things.stoleEl();
        if (things.isEmlpty())
            break;
        
    }
    std::cout << "Thief stoled all things!" << std::endl;
    
}

void addAndPop()
{
    Things things;
    srand(time(NULL));
    std::thread o(owner, std::ref(things));
    std::thread t(thief, std::ref(things));
    o.join();
    t.join();
}
#endif