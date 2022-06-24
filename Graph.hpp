#pragma once

#include "Node.hpp"
#include "ResourceCache.hpp"
#include "ILuaLibrary.hpp"
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>

class Graph : public ILuaLibrary
{
public:
	struct Edge
	{
		Node* from;
		Node* to;
	};
	struct NodeInfomation
	{
		int degree;
	};

	using EdgeVector = std::vector<Edge>;
	using EdgeMap = std::unordered_map<Node*, EdgeVector>;

	// node and its degree
	using NodeMap = std::map<Node*, NodeInfomation>;

	using ExecutionVector = std::vector<std::vector<Node*>>;

public:
	Graph();
	void Link(Node* node);
	void Link(Node* from, Node* to);
	void Compile();
	void Execute();

public:
	void Register(lua_State* vm) override;

private:
	void AddNode(Node* node);
	void Reset();

private:
	Node _root;
	NodeMap _nodes;
	EdgeMap _nodeEdges;
	ExecutionVector _executions;

	ResourceCache _resources;
};