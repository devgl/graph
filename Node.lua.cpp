#include "Node.hpp"

int Lua_CreateNode(lua_State* l)
{


	return 1;
}

int Lua_AddInput(lua_State* l)
{ 


	return 1;
}

int Node::LuaRegister(lua_State* l)
{
	luaL_Reg apis[] =
	{
		luaL_Reg{"Create", Lua_CreateNode},
		luaL_Reg{"AddInput", Lua_AddInput},
	};
	luaL_newlib(l, apis);
	return 1;
}