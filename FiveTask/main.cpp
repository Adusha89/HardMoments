#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "printUniqueWord.hpp"
#include "sortSentence.hpp"


int main(int argc, char const *argv[])
{
    std::cout << "-------------First Task----------------" << std::endl;

    std::vector<std::string> myVec = {"Hello", "world", "Hello", "andrew", "Andrew", "Hi", "Hi", "world"};
    printUniqueWord(myVec.begin(), myVec.end());
    std::cout << std::endl;

    std::list<std::string> myList = {"Hello", "world", "Hello", "andrew", "Andrew", "Hi", "Hi", "world"};
    printUniqueWord(myList.begin(), myList.end());
    std::cout << std::endl;
    
    std::deque<std::string> myDeq = {"Hello", "world", "Hello", "andrew", "Andrew", "Hi", "Hi", "world"};
    printUniqueWord(myDeq.begin(), myDeq.end());
    std::cout << std::endl;

    std::cout << "-------------Second Task----------------" << std::endl;

    //Закомментировал ввод для удобства проверки.
    // Т.к. признака конца предложения не указано было, то :
    //1. Предложение заказнчивается на .  ?   !
    //2. После знака идет пробел.
    //3. После последнего знака конец строки
    
    std::string text = "Hello! My Name is Andrew. I am from Russia.";
    //std::getline(std::cin, text);

    sortSentence(text);
    
    return 0;
}
