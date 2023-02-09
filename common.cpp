#include "common.h"

// --- common function --------------------------------------------------------
double RoundUp(double alfa)
{
	if (std::abs(alfa) < CONSTS::EPSILON)
	{
		return 0.;
	}
	return alfa;
}

double DegToRad(double alfa)
{
	return alfa * CONSTS::PI / 180;
}

std::string DoubleToString(double value, bool sign, int before_point, int after_point)
{
	std::string result;
	char sign_char;
	if (value < 0)
	{
		sign_char = '-';
		value *= -1.;
	}
	else if (sign)
	{
		sign_char = '+';
	}
	else
	{
		sign_char = ' ';
	}

	int int_part = static_cast<int>(value);
	std::vector<int> int_part_digits;
	while (int_part)
	{
		int_part_digits.push_back(int_part % 10);
		int_part /= 10;
	}
	if (int_part_digits.empty())
	{
		int_part_digits.push_back(0);
	}
	for (int i = 0; i < before_point - int_part_digits.size(); ++i)
	{
		result += ' ';
	}
	result += sign_char;
	for (int i = int_part_digits.size() - 1; i >= 0; --i)
	{
		result += std::to_string(int_part_digits.at(i));
	}
	result += '.';
	int_part = static_cast<int>(value);
	double fract_part = value - static_cast<double>(int_part);
	for (int i = 0; i < after_point; ++i)
	{
		fract_part *= 10;
		int digit = static_cast<int>(fract_part);
		fract_part -= static_cast<double>(digit);
		result += std::to_string(digit);
	}

	return result;
}

// --- class Position ---------------------------------------------------------
std::ostream& operator<<(std::ostream& out, Position pos)
{
	out << "{" << DoubleToString(pos.x, false, 2, 4) << ", " << DoubleToString(pos.y, false, 2, 4) << " }";
	return out;
}

// --- class Distance ---------------------------------------------------------
void Distance::SetDistanceKm(int distance)
{
	distance_ = distance / CONSTS::AU;
}

void Distance::SetDistanceAu(double distance)
{
	distance_ = distance;
}

double Distance::AU()
{
	return distance_;
}
