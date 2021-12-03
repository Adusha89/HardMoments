#ifndef ANALOGTODIGIT_HPP
#define ANALOGTODIGIT_HPP

#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>

template<class T>
void printVector(const std::vector<T>& vec)
{
    std::for_each(vec.begin(), vec.end(), [](T v){ std::cout << v << " ";});
}

void generateAnalog (std::vector<double>& analogSignal)
{
    srand(time(NULL));
    std::generate(analogSignal.begin(), analogSignal.end(), 
        []()->double { return static_cast<double>(rand()%90)/11; });

}

void generateDigital (const std::vector<double>& analogSignal, std::vector<int>& digitalSignal)
{
    std::transform(analogSignal.begin(), analogSignal.end(), digitalSignal.begin(), 
            [](double v){ return static_cast<int>(v);});
}

double calcError (const std::vector<double>& analogSignal, const std::vector<int>& digitalSignal)
{
    return std::inner_product(analogSignal.begin(), analogSignal.end(), digitalSignal.begin(),
           0., [](double a, double d)->double {return a+d;},[](double a, double d)->double{return (a-d)*(a-d);} );
}

#endif