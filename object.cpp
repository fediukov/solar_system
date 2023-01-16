#include "object.h"

// --- Star -------------------------------------------------------------------
Star& Star::SetName(const std::string& name)
{
	name_ = name;
	return *this;
}

Star& Star::SetRadius(int radius)
{
	radius_ = radius;
	return *this;
}

Star& Star::SetPosition(const Position& position)
{
	pos_ = position;
	return *this;
}

int Star::Time(const Date& date)
{
	return 0;
}

const Position Star::GetPosition(const Date& date)
{
	return pos_;
}

const std::string Star::GetName()
{
	return name_;
}

Object* Star::GetParent()
{
	return nullptr;
}


const Distance Star::GetDistance()
{
	Distance distance(0);
	return distance;
}

// --- Planet -----------------------------------------------------------------
Planet& Planet::SetName(const std::string& name)
{
	name_ = name;
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

Planet& Planet::SetDirection(const Direction direction)
{
	direction_ = direction;
	return *this;
}

int Planet::Time(const Date& date)
{
	return static_cast<int>(Difference(date, equinox_));
}

const Position Planet::GetPosition(const Date& date)
{
	int time = Time(date);
	double alfa = time * 360 / siderial_;
	double rad = DegToRad(alfa);
	double x = distance_.AU() * std::cos(rad);
	double y = distance_.AU() * std::sin(rad);
	y = direction_ == forward ? y : y *= -1;
	return { x + parent_->GetPosition(date).x, y + parent_->GetPosition(date).y };
}

const std::string Planet::GetName()
{
	return name_;
}

Object* Planet::GetParent()
{
	return parent_;
}

const Distance Planet::GetDistance()
{
	return distance_;
}