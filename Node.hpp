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

public:
	Field& SetType(const std::string type);
	Field& SetFormat(const std::string format);

private:
	std::string _format;
	std::string _type;
};

class Node : public Object
{
public:
	Node(const std::string name) : Object(name) {}

public:
	Field& AddInput(const std::string name);
	Field& AddOuput(const std::string name);

	const auto& GetInputs() const { return _inputs; }
	const auto& GetOutputs() const { return _outputs; }

public:
	std::vector<Field> _inputs;
	std::vector<Field> _outputs;
};

