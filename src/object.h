#pragma once

#include <string>
#include <cmath>

#include "common.h"
#include "date.h"

namespace direction
{
	enum Direction {
		forward,
		reverse
	};
} // namespace direction

using namespace direction;

class Object {
public:
	Object() {};
	~Object() = default;

	virtual Object& SetName(const std::string& name) = 0;
	virtual Object& SetRadius(int radius) = 0;

	virtual int Time(const Date& date) const = 0;
	virtual const Position GetPosition(const Date& date) const = 0;
	virtual const std::string GetName() const = 0;
	virtual Object* GetParent() = 0;
	virtual const Distance GetDistance() const = 0;

private:
};

class Star : public Object {
public:
	Star() : Object() {}

	Star& SetPosition(const Position& position);
	Star& SetName(const std::string& name) override;
	Star& SetRadius(int radius) override;

	int Time(const Date& date) const override;
	const Position GetPosition(const Date& date) const override;
	const std::string GetName() const override;
	Object* GetParent() override;
	const Distance GetDistance() const override;

private:
	std::string name_;
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
	Planet& SetDirection(const Direction direction);

	int Time(const Date& date) const override;
	const Position GetPosition(const Date& date) const override;
	const std::string GetName() const override;
	Object* GetParent() override;
	const Distance GetDistance() const override;

private:
	std::string name_;
	Object* parent_ = nullptr;
	int radius_ = 0;
	Distance distance_;
	double siderial_ = 0;
	Date equinox_ = Date(1, 1, 2000);
	Direction direction_ = forward;
};
