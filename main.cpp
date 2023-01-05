#include <iostream>

#include "date.h"
#include "object.h"
#include "solar_system.h"
#include "test_date.h"

int main()
{
    // uncomment the following to test date
    //date_tests::AllTests();

    SolarSystem solar_system = std::move(CreateSolarSystem());

    std::cout << "Commands: DD.MM.YYYY (date in this format)     next    prev    end" << std::endl;
    
    Date date;
    while (true)
    {
        std::string command;
        std::getline(std::cin, command);
        if (command == "next")
        {
            ++date;
            PrintSystem(solar_system, date);
        }
        else if (command == "prev")
        {
            --date;
            PrintSystem(solar_system, date);
        }
        else if (command == "end")
        {
            break;
        }
        else
        {
            date = Date(command);
            PrintSystem(solar_system, date);
        }
    }
    
    std::cout << std::endl;
}