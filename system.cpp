#include "system.h"

void System::AddObject(std::unique_ptr<Star>&& star)
{
	std::string name = star->GetName();
	name_object_map_[name] = std::move(star);
	objects_.push_back(name);
	Sort();
}

void System::AddObject(std::unique_ptr<Planet>&& planet)
{
	std::string name = planet->GetName();
	name_object_map_[name] = std::move(planet);
	objects_.push_back(name);
	Sort();
}

Object* System::GetParent(const std::string& name)
{
	auto it = name_object_map_.find(name);
	if (it != name_object_map_.end())
	{
		return it->second.get();
	}

	return nullptr;
}

void System::Print(const Date& date)
{
	for (const auto& object : objects_)
	{
		std::cout << object
			<< std::setprecision(6) << "\t{x,y} = " << name_object_map_.at(object)->GetPosition(date)
			<< std::endl;
	}
}

void System::Sort()
{
	auto comporator = [&](const std::string& lhs, const std::string& rhs)
	{ 
		Distance lhs_distance = name_object_map_.at(lhs)->GetDistance();
		double lhs_total_distance = lhs_distance.AU();
		Object* lhs_parent = name_object_map_.at(lhs)->GetParent();
		if (lhs_parent != nullptr)
		{
			Distance lhs_parent_distance = lhs_parent->GetDistance();
			lhs_total_distance += lhs_parent_distance.AU();
		}

		Distance rhs_distance = name_object_map_.at(rhs)->GetDistance();
		double rhs_total_distance = rhs_distance.AU();
		Object* rhs_parent = name_object_map_.at(rhs)->GetParent();
		if (rhs_parent != nullptr)
		{
			Distance rhs_parent_distance = rhs_parent->GetDistance();
			rhs_total_distance += rhs_parent_distance.AU();
		}

		return lhs_total_distance < rhs_distance.AU();
	};
	std::sort(objects_.begin(), objects_.end(), comporator);
}