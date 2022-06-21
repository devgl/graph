#include "ResourceCache.hpp"
#include <exception>

Resource& ResourceCache::UseResource(int step, const Field& field)
{
	auto itor = _cache.find(field.GetName());
	if (itor != _cache.end())
	{
		if (itor->second.begin == -1)
		{
			itor->second.begin = step;
		}
		if (step > itor->second.end)
		{
			itor->second.end = step;
		}
	}
	else
	{
		auto result = _cache.insert(std::make_pair(field.GetName(), Resource{step, -1}));
		if (result.second)
		{
			itor = result.first;
		}
		else
		{
			throw std::exception("cannot insert resource");
		}
	}
	return itor->second;	
}

Resource& ResourceCache::GetResource(std::string name)
{
	auto itor = _cache.find(name);
	if (itor != _cache.end())
	{
		return itor->second;
	}
	else
	{
		throw std::exception("resource not exist");
	}
}
