#pragma once

#include <iomanip>
#include <memory>
#include <string>
#include <vector>

#include "object.h"

using SolarSystem = std::vector<std::unique_ptr<Object>>;

struct O {
	O(std::string n, Object* p, int r, double d, double s, std::string e)
		: name(n), parent(p), radius(r), distance(d), siderial(s), equinox(e) {}

	std::string name = "";
	Object* parent = nullptr;
	int radius = 0;
	double distance = 0;
	double siderial = 0;
	std::string equinox = "";
};

SolarSystem CreateSolarSystem()
{
	SolarSystem solar_system;

	// create the sun
	std::unique_ptr<Star> sun = std::make_unique<Star>();
	sun->SetName("Sun")
		.SetRadius(695500)
		.SetPosition({ 0,0 });

	solar_system.push_back(std::move(sun));
	
	// create the planets
	std::vector<O> planets = {
		//	name		parent					radius		distance	siderial	equinox	
		O(	"Mercury",	solar_system[0].get(),	2440,		0.387,		87.969,		"20.12.2022"),
		O(	"Venus",	solar_system[0].get(),	6052,		0.723,		224.701,	"26.1.2023"),
		O(	"Earth",	solar_system[0].get(),	6370,		1,			365.256,	"23.9.2022"),
		O(	"Mars",		solar_system[0].get(),	3396,		1.5235,		686.98,		"13.7.2022"),
		O(	"Jupiter",	solar_system[0].get(),	69911,		5.2042,		4332.589,	"15.8.2022"),
		O(	"Saturn",	solar_system[0].get(),	60268,		9.582,		10759.22,	"23.10.2025"),
		O(	"Uranus",	solar_system[0].get(),	25559,		19.229,		30685.4,	"22.1.2012"),
		O(	"Neptune",	solar_system[0].get(),	24764,		30.104,		60190,		"4.10.2025")
	};

	for (const auto& p : planets)
	{
		std::unique_ptr<Planet> planet = std::make_unique<Planet>();
		planet->SetName(p.name)
			.SetSystem(p.parent)
			.SetRadius(p.radius)
			.SetDistanceAu(p.distance)
			.SetSiderial(p.siderial)
			.SetEquinox(p.equinox);
		solar_system.push_back(std::move(planet));
	}

	// create the moons
	std::vector<O> moons = {
		//	name		parent					radius		distance	siderial	equinox	
		O(	"Moon",		solar_system[3].get(),	1738,		0.00257,	27.3217,	"2.12.2022")
	};

	for (const auto& m : moons)
	{
		std::unique_ptr<Planet> moon = std::make_unique<Planet>();
		moon->SetName(m.name)
			.SetSystem(m.parent)
			.SetRadius(m.radius)
			.SetDistanceAu(m.distance)
			.SetSiderial(m.siderial)
			.SetEquinox(m.equinox);
		solar_system.push_back(std::move(moon));
	}

	return solar_system;
}

void PrintSystem(SolarSystem& system, const Date& date)
{
	for (const auto& object : system)
	{
		std::cout << object->GetName()
			<< std::setprecision(6) << "\t{x,y} = " << object->GetPosition(date) << std::endl;
	}
}
