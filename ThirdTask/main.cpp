#include <iostream>
#include <list>
#include "AverageFromList.hpp"
#include "MyMatrix.hpp"

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
    

    return 0;
}
