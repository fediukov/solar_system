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

// --- class Position ---------------------------------------------------------
std::ostream& operator<<(std::ostream& out, Position pos)
{
	out << "{" << pos.x << ",\t" << pos.y << "}";
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
