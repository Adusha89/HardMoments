#include <iostream>
#include <list>
#include "AverageFromList.hpp"
#include "MyMatrix.hpp"
#include "MyIterator.hpp"
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::cout << "----------------FIRST TASK-----------------" << std::endl;

    std::list<double> myList = {15.2, 16.1, 45.2, 49.2, 5.4};

    printList(myList);
    addAverageToList(myList);
    printList(myList);
    
    std::cout << std::endl << "----------------SECOND TASK-----------------" << std::endl;

    MyMatrix matrix(4);
    matrix.printMatrix();

    std::cout << "Determinant: " << matrix.calcDet() << std::endl;
    
    std::cout << std::endl << "----------------THIRD TASK-----------------" << std::endl;

    std::vector<int> myVec = {1,15,2,14,15,26};
    MyIterator mi(myVec);

    for (const auto& m : mi)
    {
        std::cout << m << " ";
    }

    std::sort(mi.begin(), mi.end());



    std::cout << std::endl;
    std::cout << mi[4];
    std::cout << std::endl;

    for (const auto& m : mi)
    {
        std::cout << m << " ";
    }
    std::cout << std::endl;
    return 0;
}
