#include "date.h"

// --- class Date -------------------------------------------------------------
const int Date::Day() const
{
	return day_;
}

const int Date::Month() const
{
	return month_;
}

const int Date::Year() const
{
	return year_;
}

const double Date::Days() const
{
	double time = 0;
	time += day_;
	for (int i = 0; i < month_ - 1; ++i)
	{
		time += days_in_the_month[i];
	}
	if (month_ > 2 && (year_ % 4 || (!(year_ % 100)) && year_ % 400))
	{
		--time;
	}
	int years = year_;
	while (years >= 400)
	{
		years -= 400;
		time += 146096;
	}
	while (years >= 100)
	{
		years -= 100;
		time += 36523;
	}
	while (years >= 4)
	{
		years -= 4;
		time += 1461;
	}
	while (years > 0)
	{
		--years;
		time += 365;
	}

	return time;
}

Date& Date::operator=(const Date& other)
{
	day_ = other.day_;
	month_ = other.month_;
	year_ = other.year_;
	return *this;
}

Date& Date::operator++()
{
	++day_;
	if (day_ > days_in_the_month[month_ - 1]
		// included leap years
		|| month_ == 2 && (year_%4 || (!(year_%100)) && year_%400) && day_ > (days_in_the_month[month_ - 1] - 1))
	{
		day_ = 1;
		++month_;
	}
	if (month_ > 12)
	{
		month_ = 1;
		++year_;
	}
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	++(*this);
	return tmp;
}

Date& Date::operator--()
{
	--day_;
	if (day_ < 1)
	{
		if (month_ > 1)
		{
			day_ = days_in_the_month[(--month_) - 1];
			if (month_ == 2 && (year_ % 4 || (!(year_ % 100)) && year_ % 400))
			{
				--day_;
			}
		}
		else
		{
			month_ = 12;
			day_ = days_in_the_month[month_ - 1];
			--year_;
		}
	}
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	--(*this);
	return tmp;
}

void Date::InvalidYear()
{
	if (year_ < 0)
	{
		throw ("Invalid year!");
	}
	return;
}

void Date::InvalidMonth()
{
	if (month_ < 1 || month_ > 12)
	{
		throw ("Invalid month!");
	}
	return;
}

void Date::InvalidDay()
{
	if (day_ < 1 || day_ > days_in_the_month[month_ - 1]
		// included leap years
		|| (year_ % 4 || !(year_ % 100) && year_ % 400) && month_ == 2 && day_ > (days_in_the_month[month_ - 1] - 1))
	{
		throw ("Invalid day!");
	}
	return;
}

int Date::StringToInt(const std::string& s)
{
	try
	{
		return std::stoi(s);
	}
	catch (std::invalid_argument const& /* ex */)
	{
		throw ("Invalid_argument of date!");
	}
	catch (std::out_of_range const& /* ex */)
	{
		throw ("Out_of_range of date!");
	}
}

void Date::Parse(const std::string& date)
{
	size_t i = 0;
	std::string s = "";
	while (date[i] != '.')
	{
		s += date[i];
		++i;
	}
	day_ = StringToInt(s);
	++i;
	s = "";
	while (date[i] != '.')
	{
		s += date[i];
		++i;
	}
	month_ = StringToInt(s);
	++i;
	s = "";
	while (i < date.size())
	{
		s += date[i];
		++i;
	}
	year_ = StringToInt(s);
	InvalidDay();
	InvalidMonth();
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return lhs.Day() == rhs.Day() && lhs.Month() == rhs.Month() && lhs.Year() == rhs.Year();
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Date& lhs, const Date& rhs)
{
	return lhs.Year() < rhs.Year()
		|| lhs.Year() == rhs.Year() && lhs.Month() < rhs.Month()
		|| lhs.Year() == rhs.Year() && lhs.Month() == rhs.Month() && lhs.Day() < rhs.Day();
}

bool operator<=(const Date& lhs, const Date& rhs)
{
	return lhs < rhs || lhs == rhs;
}

bool operator>(const Date& lhs, const Date& rhs)
{
	return rhs < lhs;
}

bool operator>=(const Date& lhs, const Date& rhs)
{
	return rhs < lhs || rhs == lhs;
}

std::ostream& operator<<(std::ostream& out, Date date)
{
	out << date.Day() << "." << date.Month() << "." << date.Year();
	return out;
}

double Difference(const Date& lhs, const Date& rhs)
{
	return lhs.Days() - rhs.Days();
}