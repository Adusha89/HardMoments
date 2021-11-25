#include "WarAndPeace.hpp"

WarAndPeace::WarAndPeace(std::ifstream& fin)
{
    char ch;
    while(fin >> ch)
    {
        book.push_back(ch);
    }
}

const int WarAndPeace::forFor() const
{
    int count = 0;
    for (auto b : book)
    {
        for (auto v : vowels)
        {
            if (v == b)
            {
                ++count;
                break;
            }
        }
    }

    return count;
}

const int WarAndPeace::forFind() const
{
    int count = 0;
    for (auto b : book)
    {
        if (std::find(vowels.begin(), vowels.end(), b) != vowels.end())
        {
            ++count;
        }
    }

    return count;
}

const int WarAndPeace::countifFor() const
{
    auto count = std::count_if(book.begin(), book.end(), 
        [&](char c)
            {
                for (auto v : vowels)
                {
                    if (v == c)
                    {
                        return true;
                    }
                }
                return false;
            });
    return count;
}

const int WarAndPeace::countifFind() const
{
    auto count = std::count_if(book.begin(), book.end(),
        [&](char c)
        {
            if (std::find(vowels.begin(), vowels.end(), c) != vowels.end())
            {
                return true;
            }
            return false;
        });
    return count;
}