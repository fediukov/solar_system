#include "system.h"

void System::AddObject(std::unique_ptr<Star>&& star)
{
	std::string name = star->GetName();
	objects_[name] = std::move(star);
	object_list_.push_back(objects_.at(name).get());
	is_sorted_ = false;
}

void System::AddObject(std::unique_ptr<Planet>&& planet)
{
	std::string name = planet->GetName();
	objects_[name] = std::move(planet);
	children_[objects_.at(name)->GetParent()->GetName()].push_back(objects_.at(name).get());
	object_list_.push_back(objects_.at(name).get());
	is_sorted_ = false;
}

Object* System::GetParent(const std::string& name)
{
	auto it = objects_.find(name);
	if (it != objects_.end())
	{
		return it->second.get();
	}

	return nullptr;
}

const std::vector<Object*>& System::GetObjects()
{
	if (!is_sorted_) SortByParent();
	return object_list_;
}

void System::Print(const Date& date)
{
	if (!is_sorted_)
	{
		SortByParent();
	}

	for (const auto& object : object_list_)
	{
		std::cout << object->GetName()
			<< std::setprecision(6) << "\t{x,y} = " << object->GetPosition(date)
			<< std::endl;
	}
}

void System::SortByParent()
{
	std::vector<Object*> objects;
	for (auto it = objects_.begin(); it != objects_.end(); ++it)
	{
		Object* parent = (*it).second->GetParent();
		if (parent == nullptr)
		{
			objects.push_back((*it).second.get());
			std::vector<Object*> children = std::move(GetAllChildren((*it).first));
			objects.insert(objects.end(), children.begin(), children.end());
		}
	}

	object_list_ = std::move(objects);
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

	auto it = children_.find(name);
	if (it != children_.end())
	{
		SortByDistance((*it).second);
		return (*it).second;
	}
	return {};
}

std::vector<Object*> System::GetAllChildren(const std::string& name)
{
	std::vector<Object*> all_children;
	std::vector<Object*> children = GetChildren(name);
	for (auto child : children)
	{
		std::vector<Object*> children_children = GetAllChildren(child->GetName());
		all_children.push_back(std::move(child));
		for (auto child_child : children_children)
		{
			all_children.push_back(std::move(child_child));
		}
	}

	return all_children;
}

