#pragma once

#include <algorithm>
#include <iomanip>
#include <memory>
#include <unordered_map>
#include <vector>

#include "date.h"
#include "object.h"

class System {
public:
	void AddObject(std::unique_ptr<Star>&& star);
	void AddObject(std::unique_ptr<Planet>&& object);

	Object* GetParent(const std::string& name);

	void Print(const Date& date);

private:

	void SortByParent();
	void SortByDistance(std::vector<Object*>& objects);
	std::vector<Object*> GetChildren(const std::string& name);
	std::vector<Object*> GetAllChildren(const std::string& name);

private:
	std::unordered_map<std::string, std::unique_ptr<Object>> objects_;
	std::unordered_map<std::string, std::vector<Object*>> children_;
	std::vector<Object*> object_list_;
	bool is_sorted_ = false;
};