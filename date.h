#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

const std::vector<int> days_in_the_month = { 31,29,31,30,31,30,31,31,30,31,30,31 };

// --- class Date -------------------------------------------------------------
class Date {
public:
	Date() = default;
	Date(const Date& other)
		: day_(other.day_), month_(other.month_), year_(other.year_) {}
	Date(int day, int month, int year)
		: day_(day), month_(month), year_(year)
	{
		InvalidMonth();
		InvalidDay();
	}
	Date(const std::string& date)
	{
		Parse(date);
	}

	Date& operator=(const Date& other);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	void SetDay(int day)
	{
		day_ = day;
	}

	const int Day() const;
	const int Month() const;
	const int Year() const;

	const double Days() const;

private:
	void InvalidYear();
	void InvalidMonth();
	void InvalidDay();
	int StringToInt(const std::string& s);

	void Parse(const std::string& date);

private:
	int day_;
	int month_;
	int year_;
};

bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& out, Date date);

double Difference(const Date& lhs, const Date& rhs);
