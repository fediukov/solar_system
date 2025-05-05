#pragma once

#include <iomanip>
#include <memory>
#include <string>
#include <vector>

#include "object.h"
#include "system.h"

struct ObjectHelper {
	ObjectHelper(std::string name, std::string parent, int radus,
		double distance, double sideral, std::string euinox,
		direction::Direction direction)
		: name_(name), parent_(parent), radius_(radus),
		  distance_(distance), siderial_(sideral), equinox_(euinox),
		  direction_(direction) {}

	std::string name_;
	std::string parent_ = nullptr;
	int radius_ = 0;
	double distance_ = 0;
	double siderial_ = 0;
	std::string equinox_;
	direction::Direction direction_ = direction::Direction::forward;
};

inline System CreateSolarSystem()
{
	using direction::Direction;

	System solar_system;
	
	// create the sun
	std::unique_ptr<Star> sun = std::make_unique<Star>();
	sun->SetName("Sun")
		.SetRadius(695500)
		.SetPosition({ 0,0 });

	solar_system.AddObject(std::move(sun));

	// create the planets
	std::vector<ObjectHelper> planets = {
		//			 name			parent		radius		distance	siderial	equinox			direction
		ObjectHelper("Jupiter",		"Sun",		69911,		5.2042,		4332.589,	"15.8.2022",	forward),
		ObjectHelper("Mercury",		"Sun",		2440,		0.387,		87.969,		"20.12.2022",	forward),
		ObjectHelper("Venus",		"Sun",		6052,		0.723,		224.701,	"26.1.2023",	forward),
		ObjectHelper("Earth",		"Sun",		6370,		1,			365.256,	"23.9.2022",	forward),
		ObjectHelper("Mars",		"Sun",		3396,		1.5235,		686.98,		"13.7.2022",	forward),
		ObjectHelper("Saturn",		"Sun",		60268,		9.582,		10759.22,	"23.10.2025",	forward),
		ObjectHelper("Uranus",		"Sun",		25559,		19.229,		30685.4,	"22.1.2012",	forward),
		ObjectHelper("Neptune",		"Sun",		24764,		30.104,		60190,		"4.10.2025",	forward)
	};

	for (const auto& object : planets)
	{
		std::unique_ptr<Planet> planet = std::make_unique<Planet>();
		planet->SetName(object.name_)
			.SetSystem(solar_system.GetParent(object.parent_))
			.SetRadius(object.radius_)
			.SetDistanceAu(object.distance_)
			.SetSiderial(object.siderial_)
			.SetEquinox(object.equinox_)
			.SetDirection(object.direction_);
		
		solar_system.AddObject(std::move(planet));
	}

	// create the moons
	std::vector<ObjectHelper> moons = {
		//			 name			parent		radius		distance	siderial	equinox			direction
		ObjectHelper("Moon",		"Earth",	1738,		0.00257,	27.3217,	"2.12.2022",	forward)
	};

	for (const auto& object : moons)
	{
		std::unique_ptr<Planet> moon = std::make_unique<Planet>();
		moon->SetName(object.name_)
			.SetSystem(solar_system.GetParent(object.parent_))
			.SetRadius(object.radius_)
			.SetDistanceAu(object.distance_)
			.SetSiderial(object.siderial_)
			.SetEquinox(object.equinox_)
			.SetDirection(object.direction_);

		solar_system.AddObject(std::move(moon));
	}

	return solar_system;
}