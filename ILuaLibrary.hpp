#pragma once

#include <lua.hpp>

struct ILuaLibrary
{
	virtual ~ILuaLibrary(){}
	virtual void Register(lua_State* vm) = 0;
};