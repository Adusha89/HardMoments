#ifndef PCOUT_HPP
#define PCOUT_HPP

#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <mutex>


class pCout
{
private:
static std::mutex m;
std::unique_lock<std::mutex> lock;


public:
    pCout() : lock(std::unique_lock<std::mutex>(m))
    {
        //m.lock();
    }

    ~pCout()
    {
        //m.unlock();
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
std::mutex pCout::m{};

void firstTask()
{
    std::vector<int> myVec = {1,2,3,4,5};
    std::thread th([=]()
        {
            pCout out;
            for (auto& m : myVec)
            {
                out << m << " ";
            }
            out << std::endl;
        });

    std::thread th1([=]()
        {
            pCout out;
            for (auto& m : myVec)
            {
                out << m << " ";
            }
            out << std::endl;
        });

    std::thread th2([=]()
        {
            pCout out;
            for (auto& m : myVec)
            {
                out << m << " ";
            }
            out << std::endl;
        });
    
    th.join();
    th1.join();
    th2.join();
}

#endif