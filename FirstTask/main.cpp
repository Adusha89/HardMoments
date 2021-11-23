
#include "Person.hpp"
#include "PhoneNumber.hpp"
#include "PhoneBook.hpp"



int main(int argc, char const *argv[])
{
    std::ifstream file("/home/andrew/Рабочий стол/HardMoments/FirstTask/PhoneBook.txt");

    PhoneBook book(file);
    std::cout << book;

    std::cout << std::endl << "------SortByName--------" << std::endl;
    book.sortByName();
    std::cout << book;

    std::cout << std::endl << "------SortByPhone--------" << std::endl;
    book.sortByPhone();
    std::cout << book;

    auto print_phone_number = [&book](const std::string& surname) 
    { 
        std::cout << surname << "\t"; 
        auto answer = book.getPhoneNumber(surname); 
        if (answer.first.empty()) 
            std::cout << answer.second; 
        else 
        {
            std::cout << answer.first << "  "; 
            std::cout << answer.second;
        }
        std::cout << std::endl; 
    };

    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    return 0;
}
