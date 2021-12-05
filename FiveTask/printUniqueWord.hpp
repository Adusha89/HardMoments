#ifndef PRINTUNIQUEWORD_HPP
#define PRINTUNIQUEWORD_HPP

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

template<typename Iter>
void printUniqueWord (Iter it, Iter it2)
{
    std::set<std::string> mySet;
    std::copy(it, it2, std::inserter(mySet, mySet.end()));
    std::for_each(mySet.begin(), mySet.end(), [](const std::string& s){std::cout << s << std::endl; });
}

#endif