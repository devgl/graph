#include "Graph.hpp"
#include "Node.hpp"

int main()
{
	Graph* graph = new Graph();
	auto* depthPass = new Node("DepthPass");
	depthPass->AddField("DepthTexture");

	auto* opaquePass = new Node("OpaquePass");
	opaquePass->AddField("DepthStencilTexture");

	graph->AddNode(depthPass);
	graph->AddNode(opaquePass);

	graph->Link(depthPass, "DepthTexture", opaquePass, "DepthStencilTexture");

	auto* edges = graph->GetNodeEdges(depthPass);


	return 0;
}