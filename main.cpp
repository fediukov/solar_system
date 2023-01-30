#include <iostream>

#include "date.h"
#include "solar_system.h"
#include "system.h"
#include "test_date.h"

int main()
{
    // uncomment the following to test date
    //date_tests::AllTests();

    System solar_system = std::move(CreateSolarSystem());

    std::cout << "Commands: DD.MM.YYYY (date in this format)     next    prev    end" << std::endl;
    
    Date date;
    while (true)
    {
        std::string command;
        std::getline(std::cin, command);
        if (command == "next")
        {
            ++date;
            solar_system.Print(date);
        }
        else if (command == "prev")
        {
            --date;
            solar_system.Print(date);
        }
        else if (command == "end")
        {
            break;
        }
        else
        {
            date = Date(command);
            solar_system.Print(date);
        }
    }
    
    std::cout << std::endl;
}