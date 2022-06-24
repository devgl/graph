#include "Graph.hpp"

int Lua_AddNode(lua_State* vm)
{
	auto graph = (Graph*)lua_touserdata(vm, 0);
	auto newNode = (Node*)lua_touserdata(vm, 1);

	graph->Link(newNode);

	return 0;
}

int Lua_Link(lua_State* vm)
{
	return 0;
}

int Graph::LuaRegister(lua_State* vm)
{
	luaL_Reg apis[] =
	{
		luaL_Reg{"AddNode", Lua_AddNode},
		luaL_Reg{"Link", Lua_Link},
		{nullptr, nullptr}
	};
	luaL_newlib(vm, apis);
	return 1;
}