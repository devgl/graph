#include "Graph.hpp"
#include "Node.hpp"
#include <lua.hpp>
#include <iostream>

int main()
{
	Graph* graph = new Graph();
	auto* depthPass = new Node("DepthPass");
	depthPass->AddOuput("DepthTexture")
		.SetType("DepthStencil")
		.SetFormat("D24S8");

	auto* opaquePass = new Node("OpaquePass");
	opaquePass->AddInput("DepthStencilTexture");

	auto* dummyPass = new Node("DummyPass");

	graph->Link(depthPass, opaquePass);
	graph->Link(dummyPass);
	graph->Compile();
	graph->Execute();

	auto luaVM = luaL_newstate();
	luaL_openlibs(luaVM);
	lua_register(luaVM, "open_GraphLib", &Graph::LuaRegister);
	lua_register(luaVM, "open_NodeLib", &Node::LuaRegister);

	auto ret = luaL_dofile(luaVM, SCRIPT("main.lua"));
	if (ret != 0) 
	{
		std::cout << "Error: " << lua_tostring(luaVM, -1);
	}
	lua_close(luaVM);

	return 0;
}