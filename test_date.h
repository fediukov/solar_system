#pragma once

#include <cassert>

#include "date.h"

namespace date_tests
{
    void TestIncrement()
    {
        // check the border of the months
        Date date(29, 11, 2022);
        assert(date == Date(29, 11, 2022));
        assert(date++ == Date(29, 11, 2022));
        assert(date == Date(30, 11, 2022));
        assert(++date == Date(1, 12, 2022));
        assert(date == Date(1, 12, 2022));
        assert(date-- == Date(1, 12, 2022));
        assert(date == Date(30, 11, 2022));
        assert(--date == Date(29, 11, 2022));
        // check the border of the years
        Date date2(31, 12, 2021);
        assert(date2++ == Date(31, 12, 2021));
        assert(date2 == Date(1, 1, 2022));
        assert(date2-- == Date(1, 1, 2022));
        assert(date2 == Date(31, 12, 2021));
        assert(++date2 == Date(1, 1, 2022));
        assert(--date2 == Date(31, 12, 2021));
        // check the border of the February
        Date date3(28, 2, 2021);
        assert(date3++ == Date(28, 2, 2021));
        assert(date3 == Date(1, 3, 2021));
        assert(date3-- == Date(1, 3, 2021));
        assert(date3 == Date(28, 2, 2021));
        assert(++date3 == Date(1, 3, 2021));
        assert(--date3 == Date(28, 2, 2021));
        Date date4(28, 2, 2020);
        assert(date4++ == Date(28, 2, 2020));
        assert(date4++ == Date(29, 2, 2020));
        assert(date4 == Date(1, 3, 2020));
        assert(date4-- == Date(1, 3, 2020));
        assert(date4 == Date(29, 2, 2020));
        assert(++date4 == Date(1, 3, 2020));
        assert(--date4 == Date(29, 2, 2020));
        Date date5(28, 2, 1900);
        assert(date5++ == Date(28, 2, 1900));
        assert(date5 == Date(1, 3, 1900));
        assert(date5-- == Date(1, 3, 1900));
        assert(date5 == Date(28, 2, 1900));
        assert(++date5 == Date(1, 3, 1900));
        assert(--date5 == Date(28, 2, 1900));
        Date date6(28, 2, 1600);
        assert(date6++ == Date(28, 2, 1600));
        assert(date6++ == Date(29, 2, 1600));
        assert(date6 == Date(1, 3, 1600));
        assert(date6-- == Date(1, 3, 1600));
        assert(date6 == Date(29, 2, 1600));
        assert(++date6 == Date(1, 3, 1600));
        assert(--date6 == Date(29, 2, 1600));

        std::cout << "TestIncrement is OK" << std::endl;
    }

    void TestComparison()
    {
        Date date(2, 2, 1599);
        Date date1(3, 2, 1599);
        Date date2(2, 3, 1599);
        Date date3(2, 2, 1600);
        Date date4(2, 2, 1599);
        assert(date == date4);
        assert(date != date3);
        assert(date != date2);
        assert(date != date1);
        assert(date <= date4);
        assert(date <= date3);
        assert(date <= date2);
        assert(date <= date1);
        assert(date < date3);
        assert(date < date2);
        assert(date < date1);
        assert(date3 > date);
        assert(date2 > date);
        assert(date1 > date);
        assert(date4 >= date);
        assert(date3 >= date);
        assert(date2 >= date);
        assert(date1 >= date);

        std::cout << "TestComparison is OK" << std::endl;
    }

    void TestString()
    {
        assert(Date(31, 12, 2021) == Date("31.12.2021"));
        assert(Date(3, 12, 2021) == Date("3.12.2021"));
        assert(Date(7, 2, 2021) == Date("7.2.2021"));
        assert(Date(1, 1, 2021) == Date("1.1.2021"));

        std::cout << "TestString is OK" << std::endl;
    }

    void TestDays()
    {
        assert(Date(31, 12, 2021).Days() == 738515);
        assert(Date(1, 1, 2022).Days() == 738516);
        assert(Date(1, 1, 2023).Days() == 738881);
        assert(Date(28, 2, 2024).Days() == 739305);
        assert(Date(1, 3, 2024).Days() == 739307);
        assert(Date(1, 1, 2122).Days() == 775039);
        assert(Date(1, 3, 2122).Days() == 775098);
        assert(Date(1, 4, 2122).Days() == 775129);
        assert(Date(1, 5, 2122).Days() == 775159);
        assert(Date(1, 6, 2122).Days() == 775190);
        assert(Date(1, 7, 2122).Days() == 775220);
        assert(Date(1, 8, 2122).Days() == 775251);
        assert(Date(1, 9, 2122).Days() == 775282);
        assert(Date(1, 10, 2122).Days() == 775312);
        assert(Date(2, 11, 2122).Days() == 775344);
        assert(Date(12, 12, 2122).Days() == 775384);
        assert(Date(1, 1, 2400).Days() == 876577);
        assert(Date(10, 2, 2400).Days() == 876617);
        assert(Date(10, 3, 2400).Days() == 876646);

        std::cout << "TestDays is OK" << std::endl;
    }

    void AllTests()
    {
        TestIncrement();
        TestComparison();
        TestString();
        TestDays();

        std::cout << "All the tests are OK" << std::endl;
    }
} // namespace date_tests