#include <iostream>
#include "AnalogToDigit.hpp"
#include "InsertSorted.hpp"
#include <vector>

int main(int argc, char const *argv[])
{
    std::cout << "----------------First Task-----------------" << std::endl;
    std::vector<int> myVec = {1, 7, 9, 11, 11, 17, 21, 22};
    insertSorted(myVec, 11);
    printVector(myVec);
    std::cout << std::endl;

    std::vector<int> myVec1 = {22, 20, 18, 15, 15, 10, 9};
    insertSorted(myVec1, 3);
    printVector(myVec1);
    std::cout << std::endl;

    std::cout << "----------------Second Task-----------------" << std::endl;
    std::vector<double> analogSignal(100);
    generateAnalog(analogSignal);
    printVector(analogSignal);
    
    std::cout << std::endl;

    std::vector<int> digitalSignal(100);
    generateDigital(analogSignal, digitalSignal);
    printVector(digitalSignal);

    std::cout << std::endl << "Error is: " << calcError(analogSignal, digitalSignal) << std::endl;
    return 0;
}
