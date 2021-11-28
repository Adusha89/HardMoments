#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "WarAndPeace.hpp"
#include "Timer.hpp"

#define MAX 15

template<class T>
void swapMy (T** first, T** second)
{
    T* temp = *first;
    *first = *second;
    *second = temp;
}

template<class T>
void sortPointers (std::vector<T*>& myVector)
{
    std::sort(myVector.begin(), myVector.end(), [](T* one, T* second){return *one < *second;});
}

int main ()
{   
    std::cout << "--------------Swap pointer------------" << std::endl;

    int *a = new int(5);
    int *b = new int(7);

    std::cout << "a adress: " << a << " value: " << *a << std::endl;
    std::cout << "b adress: " << b << " value: " << *b << std::endl;

    swapMy(&a, &b);

    std::cout << "a adress: " << a << " value: " << *a << std::endl;
    std::cout << "b adress: " << b << " value: " << *b << std::endl;

    delete a;
    delete b;

    std::cout << "--------------Sort pointers------------" << std::endl;

    std::vector<int*> myVector;

    for (size_t idx = 0; idx < MAX; ++idx)
    {
        int* t = new int((rand() % MAX + 1));
        myVector.push_back(t);
    }

    for (auto n : myVector)
    {
        std::cout << *n << " ";
    }
    std::cout << std::endl;

    sortPointers(myVector);

    for (auto n : myVector)
    {
        std::cout << *n << " ";
    }
    std::cout << std::endl;

    for (auto n : myVector)
    {
        delete n;
    }

    std::cout << "--------------War And Peace------------" << std::endl;

    std::ifstream fin("War and peace.txt");
    WarAndPeace book(fin);

    Timer time;

    time.start("For-For");
    std::cout << "Result For-For: " << book.forFor() << std::endl;
    time.print();

    time.start("For-Find");
    std::cout << "Result For-Find: " << book.forFind() << std::endl;
    time.print();

    time.start("CountifFor");
    std::cout << "Result CountifFor: " << book.countifFor() << std::endl;
    time.print();

    time.start("CountifFind");
    std::cout << "Result CountifFind: " << book.countifFind() << std::endl;
    time.print();
    
    
    return 0;
}