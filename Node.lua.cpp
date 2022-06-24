#include "Node.hpp"

int Lua_CreateNode(lua_State* l)
{
	size_t len = 0;
	const char* name = lua_tolstring(l, 1, &len);
	std::string strName(name, len);
	Node* pNode = new Node(strName);
	lua_pushlightuserdata(l, pNode);
	return 1;
}

int Lua_AddInput(lua_State* l)
{ 
	Node* pNode = (Node*)lua_touserdata(l, 1);

	size_t len = 0;
	const char* name = lua_tolstring(l, 2, &len);
	std::string strName(name, len);

	pNode->AddInput(strName);

	return 1;
}

int Node::LuaRegister(lua_State* l)
{
	luaL_Reg apis[] =
	{
		luaL_Reg{"Create", Lua_CreateNode},
		luaL_Reg{"AddInput", Lua_AddInput},
		luaL_Reg{nullptr, nullptr},
	};
	luaL_newlib(l, apis);
	return 1;
}