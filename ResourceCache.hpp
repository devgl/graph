#pragma once

#include "Node.hpp"
#include <string>
#include <unordered_map>

struct Resource
{
	int begin;
	int end;
};

class ResourceCache
{
public:
	Resource& UseResource(int step, const Field& field);
	Resource& GetResource(std::string name);

private:
	std::unordered_map<std::string, Resource> _cache;
};