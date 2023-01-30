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
	if (value < 0)
	{
		result += "-";
		value *= -1.;
	}
	else
	{
		if (sign)
		{
			result += "+";
		}
		else
		{
			result += " ";
		}
	}
	int int_part = static_cast<int>(value);
	std::vector<int> int_part_digits;
	while (int_part)
	{
		int_part_digits.push_back(int_part % 10);
		int_part /= 10;
	}
	while (int_part_digits.size() < before_point)
	{
		int_part_digits.push_back(0);
	}
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
