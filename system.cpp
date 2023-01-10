#include "system.h"

void System::AddObject(std::unique_ptr<Star>&& star)
{
	std::string name = star->GetName();
	name_object_map_[name] = std::move(star);
	objects_.push_back(name_object_map_.at(name).get());
	is_sorted_ = false;
}

void System::AddObject(std::unique_ptr<Planet>&& planet)
{
	std::string name = planet->GetName();
	name_object_map_[name] = std::move(planet);
	objects_.push_back(name_object_map_.at(name).get());
	is_sorted_ = false;
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
	if (!is_sorted_)
	{
		SortByParent();
	}

	for (const auto& object : objects_)
	{
		std::cout << object->GetName()
			<< std::setprecision(6) << "\t{x,y} = " << object->GetPosition(date)
			<< std::endl;
	}
}

void System::SortByParent()
{
	std::vector<Object*> objects;
	for (auto it = name_object_map_.begin(); it != name_object_map_.end(); ++it)
	{
		Object* parent = (*it).second->GetParent();
		if (parent == nullptr)
		{
			objects.push_back((*it).second.get());
			std::vector<Object*> children = std::move(GetAllChildren((*it).first));
			objects.insert(objects.end(), children.begin(), children.end());
		}
	}

	objects_ = std::move(objects);
	is_sorted_ = true;
}

void System::SortByDistance(std::vector<Object*>& objects)
{
	auto comporator = [&](Object* lhs, Object* rhs)
	{
		Distance lhs_distance = lhs->GetDistance(), rhs_distance = rhs->GetDistance();
		return lhs_distance.AU() < rhs_distance.AU();
	};

	std::sort(objects.begin(), objects.end(), comporator);
}

std::vector<Object*> System::GetChildren(const std::string& name)
{
	std::vector<Object*> children;
	for (auto it = name_object_map_.begin(); it != name_object_map_.end(); ++it)
	{
		Object* parent = it->second.get()->GetParent();
		if (parent != nullptr && parent->GetName() == name)
		{
			children.push_back(it->second.get());
		}
	}

	SortByDistance(children);
	return children;
}

std::vector<Object*> System::GetAllChildren(const std::string& name)
{
	std::vector<Object*> children = std::move(GetChildren(name));
	for (auto it = children.begin(); it != children.end(); ++it)
	{
		std::vector<Object*> children_children = GetAllChildren((*it)->GetName());
		children.insert(std::next(it, 1), children_children.begin(), children_children.end());
	}

	return children;
}

