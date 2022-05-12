#include "Node.hpp"

Field& Node::AddField(const std::string name)
{
	_fields.push_back(Field(name)); 
	return _fields.back();
}
