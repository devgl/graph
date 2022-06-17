#include "Graph.hpp"
#include <iostream>

Graph::Graph()
	: _root("GraphRoot")
{
	Reset();
}



void Graph::Reset()
{
	_nodes.clear();
	_nodes.insert(std::make_pair(&_root, NodeInfomation{0}));

	_nodeEdges.clear();
	_nodeEdges.insert(std::make_pair(&_root, EdgeVector{}));
}

void Graph::AddNode(Node* node)
{
	if (_nodes.find(node) == _nodes.end())
	{
		_nodes.insert(std::make_pair(node, NodeInfomation{1}));
		_nodeEdges[&_root].push_back(Edge{ &_root, node });
	}
}

void Graph::Link(Node* node)
{
	AddNode(node);
}

void Graph::Link(Node* from, Node* to)
{
	AddNode(from);
	AddNode(to);

	auto itor = _nodeEdges.find(from);
	if (itor != _nodeEdges.end())
	{
		itor->second.emplace_back(Edge{ from, to });
	}
	else
	{
		_nodeEdges.insert(std::make_pair(from, EdgeVector{ Edge{ from, to } }));
	}
	_nodes[to].degree++;
}

void Graph::Compile()
{
	while (_nodes.size() > 0)
	{
		std::vector<Node*> frameNodes;
		for (auto const& nodeInfo : _nodes)
		{
			if (nodeInfo.second.degree == 0)
			{
				frameNodes.push_back(nodeInfo.first);
			}
		}
		for (auto const& node : frameNodes)
		{
			_nodes.erase(node);
		}
		for (auto const& node : frameNodes)
		{
			const auto& edges = _nodeEdges[node];
			for (auto const& edge : edges)
			{
				_nodes[edge.to].degree--;
			}
		}

		_executions.push_back(frameNodes);
	}

	Reset();
}

void Graph::Execute()
{
	for (auto const& section : _executions)
	{
		std::cout << "---passes running in parallel---begin---" << '\n';

		// print frame nodes
		for (auto const& node : section)
		{
			std::cout << node->GetName() << "->";
		}

		std::cout << '\n' << "---end---" << '\n';
	}

	_executions.clear();
}



