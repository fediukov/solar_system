#pragma once

#include <string>
#include <cmath>

#include "common.h"
#include "date.h"

class Object {
public:
	Object() {};
	~Object() = default;

	virtual Object& SetName(const std::string& name) = 0;
	virtual Object& SetRadius(int radius) = 0;

	virtual int Time(const Date& date) = 0;
	virtual const Position GetPosition(const Date& date) = 0;
	virtual const std::string GetName() = 0;

private:
};

class Solar : public Object {
public:
	Solar() : Object() {}

	Solar& SetPosition(const Position& position);
	Solar& SetName(const std::string& name) override;
	Solar& SetRadius(int radius) override;

	int Time(const Date& date) override;
	const Position GetPosition(const Date& date) override;
	const std::string GetName() override;

private:
	std::string name_ = "";
	int radius_ = 0;
	Position pos_ = { 0,0 };
};

class Planet : public Object {
public:
	Planet() : Object() {}

	Planet& SetName(const std::string& name) override;
	Planet& SetSystem(Object* parent);
	Planet& SetRadius(int radius) override;
	Planet& SetDistanceKm(int distance);
	Planet& SetDistanceAu(double distance);
	Planet& SetSiderial(double siderial);
	Planet& SetEquinox(const std::string& equinox);

	int Time(const Date& date) override;
	const Position GetPosition(const Date& date) override;
	const std::string GetName() override;

private:
	std::string name_ = "";
	Object* parent_ = nullptr;
	int radius_ = 0;
	Distance distance_;
	double siderial_ = 0;
	Date equinox_ = Date(1, 1, 2000);
};
