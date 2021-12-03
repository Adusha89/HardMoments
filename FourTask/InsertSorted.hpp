#ifndef INSERTSORTED_HPP
#define INSERTSORTED_HPP

template<class T>
void insertSorted (std::vector<T>& myVec, T insertData)
{
    if (*myVec.begin() < *(myVec.end()-1))
    {
        myVec.insert(std::lower_bound(myVec.begin(), myVec.end(), insertData), insertData);
    }
    else
    {
        myVec.insert(std::lower_bound(myVec.rbegin(), myVec.rend(), insertData).base(), insertData);
    }
}

#endif