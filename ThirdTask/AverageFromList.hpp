#ifndef AVERAGEFROMLIST_HPP
#define AVERAGEFROMLIST_HPP

#include <list>


void addAverageToList (std::list<double>& myList)
{
    double averageTemp = 0;
    for (const auto& l : myList)
    {
        averageTemp += l;
    }

    myList.push_back(averageTemp/myList.size());
}

void printList (const std::list<double>& myList)
{
    for (const auto& l : myList)
    {
        std::cout << l << " ";
    }
    std::cout << std::endl;
}

#endif