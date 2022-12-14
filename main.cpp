#include <cassert>
#include <iomanip>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <stdint.h>
#include <vector>

#include "date.h"
#include "object.h"
#include "solar_system.h"
#include "test_date.h"

void PrintSystem(SolarSystem& system, const Date& date)
{
    for (const auto& o : system)
    {
        std::cout << o->GetName()
            << std::setprecision(6) << "\t{x,y} = " << o->GetPosition(date) << std::endl;
    }
}

int main()
{
    // check date
    //date_tests::AllTests();

    SolarSystem solar_system = std::move(CreateSolarSystem());

    std::cout << "Comands: DD.MM.YYYY (date in this format)     next    prev    end" << std::endl;
    
    Date date;
    while (true)
    {
        std::string s = "";
        std::getline(std::cin, s);
        if (s == "next")
        {
            ++date;
            PrintSystem(solar_system, date);
        }
        else if (s == "prev")
        {
            --date;
            PrintSystem(solar_system, date);
        }
        else if (s == "end")
        {
            break;
        }
        else
        {
            try
            {
                date = Date(s);
                PrintSystem(solar_system, date);
            }
            catch (...)
            {
                std::cout << "Uncorrect date!" << std::endl;
            }
        }
    }
    
    std::cout << std::endl;
}