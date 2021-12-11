#ifndef PCOUT_HPP
#define PCOUT_HPP

#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <mutex>
std::mutex m;

class pCout
{

public:
    pCout()
    {
        m.lock();
    }

    ~pCout()
    {
        m.unlock();
    }

    template<class T>
    pCout& operator<< (const T& data)
    {
        std::cout << data;
        return *this;
    }
    pCout& operator<< (std::ostream& (*data)(std::ostream&)) // Для вывода endl
    {
        std::cout << data;
        return *this;
    }
};

void firstTask()
{
    std::vector<int> myVec = {1,2,3,4,5};
    std::thread th([=]()
        {
            for (auto& m : myVec)
            {
                pCout() << m << " ";
            }
            pCout() << std::endl;
        });

    std::thread th1([=]()
        {
            for (auto& m : myVec)
            {
                pCout() << m << " ";
            }
            pCout() << std::endl;
        });

    std::thread th2([=]()
        {
            for (auto& m : myVec)
            {
                pCout() << m << " ";
            }
            pCout() << std::endl;
        });
    
    th.join();
    th1.join();
    th2.join();
}

#endif