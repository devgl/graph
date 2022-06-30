#include "Node.hpp"

// Field -----------------------------------------

int Lua_Field_SetType(lua_State* l)
{
	auto* f = (Field*)lua_touserdata(l, 1);

	size_t len = 0;
	const char* name = lua_tolstring(l, 2, &len);
	std::string strName(name, len);
	
	f->SetType(strName);
	return 0;
}

int Lua_Field_GetType(lua_State* l)
{
	auto* f = (Field*)lua_touserdata(l, 1);

	const auto& name = f->GetType();
	lua_pushlstring(l, name.c_str(), name.length());
	return 1;
}

int Lua_Field_SetFormat(lua_State* l)
{
	auto* f = (Field*)lua_touserdata(l, 1);

	size_t len = 0;
	const char* name = lua_tolstring(l, 2, &len);
	std::string strName(name, len);
	
	f->SetFormat(strName);
	return 0;
}

int Lua_Field_GetFormat(lua_State* l)
{
	auto* f = (Field*)lua_touserdata(l, 1);

	const auto& name = f->GetFormat();
	lua_pushlstring(l, name.c_str(), name.length());
	return 1;
}

int Lua_Field_GetName(lua_State* l)
{
	auto* f = (Field*)lua_touserdata(l, 1);

	const auto& name = f->GetName();
	lua_pushlstring(l, name.c_str(), name.length());
	return 1;
}

int Field::LuaRegister(lua_State* l)
{
	luaL_Reg apis[] =
	{
		luaL_Reg{"SetType", &Lua_Field_SetType},
		luaL_Reg{"GetType", &Lua_Field_GetType},
		luaL_Reg{"SetFormat", &Lua_Field_SetFormat},
		luaL_Reg{"GetFormat", &Lua_Field_GetFormat},
		luaL_Reg{"GetName", &Lua_Field_GetName},
		luaL_Reg{nullptr, nullptr}
	};
	luaL_newlib(l, apis);
	return 1;
}

// Node --------------------------------------------

int Lua_Node_Create(lua_State* l)
{
	size_t len = 0;
	const char* name = lua_tolstring(l, 1, &len);
	auto* n = new Node(std::string(name, len));
	lua_pushlightuserdata(l, n);
	return 1;
}

int Lua_Node_Destroy(lua_State* l)
{
	auto* n = (Node*)lua_touserdata(l, 1);
	delete n;
	return 0;
}

int Lua_Node_GetName(lua_State* l)
{
	auto* n = (Node*)lua_touserdata(l, 1);
	const auto& name = n->GetName();
	lua_pushlstring(l, name.c_str(), name.length());
	return 1;
}

int Lua_Node_AddInput(lua_State* l)
{ 
	size_t len = 0;
	const char* name = lua_tolstring(l, 2, &len);
	auto* n = (Node*)lua_touserdata(l, 1);
	Field& f = n->AddInput(std::string(name, len));
	lua_pushlightuserdata(l, &f);
	return 1;
}

int Lua_Node_AddOutput(lua_State* l)
{
	size_t len = 0;
	const char* name = lua_tolstring(l, 2, &len);
	auto* n = (Node*)lua_touserdata(l, 1);
	Field& f = n->AddOuput(std::string(name, len));
	lua_pushlightuserdata(l, &f);
	return 1;
}

int Node::LuaRegister(lua_State* l)
{
	luaL_Reg apis[] =
	{
		luaL_Reg{"Create", &Lua_Node_Create},
		luaL_Reg{"Destroy", &Lua_Node_Destroy},
		luaL_Reg{"GetName", &Lua_Node_GetName},
		luaL_Reg{"AddInput", &Lua_Node_AddInput},
		luaL_Reg{"AddOutput", &Lua_Node_AddOutput},
		luaL_Reg{nullptr, nullptr}
	};
	luaL_newlib(l, apis);
	return 1;
}
