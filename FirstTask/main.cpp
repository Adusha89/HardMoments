
#include "Person.hpp"
#include "PhoneNumber.hpp"
#include "PhoneBook.hpp"



int main(int argc, char const *argv[])
{
    std::ifstream file("PhoneBook.txt");
    if (!file.is_open())
    {
        std::cout << "File don't open! Check the path" << std::endl;
        return 0;
    }

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
            std::cout << answer.second << std::endl;
        else 
        {
            std::cout << answer.first << "  " << answer.second << std::endl;
        }
    };

    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    std::cout << "----ChangePhoneNumber----" << std::endl;
    book.changePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{7, 123, "15344458", std::nullopt});
    book.changePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << book << std::endl;

    return 0;
}
