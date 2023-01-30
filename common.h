#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// --- constants --------------------------------------------------------------
namespace CONSTS
{
	const int AU = 150'000'000;
	const double PI = 3.14159265359;
	const double EPSILON = 1.0e-6;
} // namespace CONSTS

// --- common functions -------------------------------------------------------
double RoundUp(double alfa);
double DegToRad(double alfa);
std::string DoubleToString(double value, bool sign, int before_point, int after_point);

// --- class Position ---------------------------------------------------------
struct Position {
	double x;
	double y;
};

std::ostream& operator<<(std::ostream& out, Position pos);

// --- class Distance ---------------------------------------------------------
class Distance {
public:
	Distance() = default;
	Distance(double distance_)
		: distance_(distance_) {};

	void SetDistanceKm(int distance);
	void SetDistanceAu(double distance);
	double AU();

private:
	double distance_ = 0; // distance in au
};

