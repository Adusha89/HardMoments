#ifndef SORTSENTENCE_HPP
#define SORTSENTENCE_HPP

#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>

void sortSentence (const std::string& myStr)
{
    std::multimap<int, std::string> myMap;

    int len = 0;
    std::string tempStr;

    for (auto it = myStr.begin(); it != myStr.end(); ++it)
    {
        ++len;
        tempStr.push_back(*it);

        if ((*it == '.') || (*it == '!') || (*it == '?'))
        {
            myMap.insert({len, tempStr});
            len = 0;
            tempStr.erase();
            if (*(it+1) == ' ')
            {
                ++it;
            }
        }
    }

    std::for_each (myMap.begin(), myMap.end(), 
        []( std::pair<int, std::string> p)
            {
                std::cout << "Lenght: " << p.first << " Sentence: " << p.second << std::endl;
            });
}


#endif