#pragma once

#include <algorithm>
#include <iomanip>
#include <memory>
#include <unordered_map>
#include <vector>

#include "object.h"

class System {
public:
	void AddObject(std::unique_ptr<Star>&& star);
	void AddObject(std::unique_ptr<Planet>&& object);

	Object* GetParent(const std::string& name);

	void Print(const Date& date);

private:
	void Sort();

private:
	std::vector<std::string> objects_;
	std::unordered_map<std::string, std::unique_ptr<Object>> name_object_map_;

};