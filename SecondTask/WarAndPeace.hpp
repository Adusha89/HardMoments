#ifndef WARANDPEACE_HPP
#define WARANDPEACE_HPP

#include <vector>
#include <fstream>
#include <algorithm>

class WarAndPeace
{
private:
    std::vector<char> book;
    std::vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};

public:
    WarAndPeace(std::ifstream&);
    

    const int forFor() const;
    const int forFind() const;
    const int countifFor() const;
    const int countifFind() const;
};

#endif
