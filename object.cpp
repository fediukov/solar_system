#include "object.h"

// --- sets -------------------------------------------------------------------
Solar& Solar::SetName(const std::string& name)
{
	name_ = name;
	return *this;
}

Solar& Solar::SetRadius(int radius)
{
	radius_ = radius;
	return *this;
}

Solar& Solar::SetPosition(const Position& position)
{
	pos_ = position;
	return *this;
}

Planet& Planet::SetName(const std::string& name)
{
	name_ = std::move(name);
	return *this;
}

Planet& Planet::SetSystem(Object* parent)
{
	parent_ = parent;
	return *this;
}

Planet& Planet::SetRadius(int radius)
{
	radius_ = radius;
	return *this;
}

Planet& Planet::SetDistanceKm(int distance)
{
	distance_.SetDistanceKm(distance);
	return *this;
}

Planet& Planet::SetDistanceAu(double distance)
{
	distance_.SetDistanceAu(distance);
	return *this;
}

Planet& Planet::SetSiderial(double siderial)
{
	siderial_ = siderial;
	return *this;
}

Planet& Planet::SetEquinox(const std::string& equinox)
{
	equinox_ = Date(equinox);
	return *this;
}

// --- gets -------------------------------------------------------------------
int Solar::Time(const Date& date)
{
	return 0;
}

const std::string Solar::GetName()
{
	return name_;
}

const Position Solar::GetPosition(const Date& date)
{
	return pos_;
}

int Planet::Time(const Date& date)
{
	return static_cast<int>(Difference(date, equinox_));
}

const std::string Planet::GetName()
{
	return name_;
}

const Position Planet::GetPosition(const Date& date)
{
	int time = Time(date);
	double alfa = time * 360 / siderial_;
	double rad = DegToRad(alfa);
	double x = distance_.AU() * std::cos(rad);
	double y = distance_.AU() * std::sin(rad);
	return { x + parent_->GetPosition(date).x, y + parent_->GetPosition(date).y };
}//*/
