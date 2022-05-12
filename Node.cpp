#include "Node.hpp"

Field& Node::AddInput(const std::string name)
{
	_inputs.push_back(Field(name));
	return _inputs.back();
}

Field& Node::AddOuput(const std::string name)
{
	_outputs.push_back(Field(name));
	return _outputs.back();
}

Field& Field::SetType(const std::string type)
{
	_type = type;
	return *this;
}

Field& Field::SetFormat(const std::string format)
{
	_format = format;
	return *this;
}
