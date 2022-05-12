#pragma once

#include <string>
#include <vector>

class Object
{
public:

	Object(const std::string name) : _name(name) {	}
	const auto& GetName() const { return _name; }

private:
	std::string _name;
};

class Field : public Object
{
public:
	Field(const std::string name) : Object(name) {}
};

class Node : public Object
{
public:
	Node(const std::string name) : Object(name) {}

public:
	Field& AddField(const std::string name);

public:
	std::vector<Field> _fields;
};