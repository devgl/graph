#pragma once

#include "Node.hpp"
#include <set>
#include <unordered_map>
#include <cassert>

class Graph
{
public:
	struct Edge
	{
		Node* from;
		Node* to;
		std::string fromField;
		std::string toField;
	};

	using EdgeVector = std::vector<Edge>;
	using NodeEdges = std::unordered_map<Node*, EdgeVector>;

public:
	void AddNode(Node* node)
	{
		if (_nodes.find(node) == _nodes.end())
		{
			_nodes.insert(node);
		}
	}

	void Link(Node* from, std::string fromFieldName, Node* to, std::string toFieldName)
	{
		assert(_nodes.find(from) != _nodes.end());
		assert(_nodes.find(to) != _nodes.end());

		auto itor = _nodeEdges.find(from);
		if (itor != _nodeEdges.end())
		{
			itor->second.emplace_back(Edge{ from, to, fromFieldName, toFieldName });
		}
		else
		{
			_nodeEdges.insert(std::make_pair(from, EdgeVector{ Edge{from, to, fromFieldName, toFieldName} }));
		}
	}

	const EdgeVector* GetNodeEdges(Node* node)
	{
		auto itor = _nodeEdges.find(node);
		if (itor != _nodeEdges.end())
		{
			return &itor->second;
		}
		else
		{
			return nullptr;
		}
	}

private:
	std::set<Node*> _nodes;
	NodeEdges _nodeEdges;
};