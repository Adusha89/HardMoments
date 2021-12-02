#ifndef MYITERATOR_HPP
#define MYITERATOR_HPP

#include <vector>

class MyIterator
{
private:
    std::vector<int> m_data;

public:
    MyIterator(const std::vector<int>& data) : m_data(data) {}
    std::vector<int>::iterator begin()
    {
        return m_data.begin();
    }

    std::vector<int>::iterator end()
    {
        return m_data.end();
    }

    int operator[] (int n) const
    {
        return m_data[n];
    }

};

#endif
