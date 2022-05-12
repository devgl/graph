#include "Graph.hpp"
#include "Node.hpp"

int main()
{
	Graph* graph = new Graph();
	auto* depthPass = new Node("DepthPass");
	depthPass->AddOuput("DepthTexture")
		.SetType("DepthStencil")
		.SetFormat("R24D8");

	auto* opaquePass = new Node("OpaquePass");
	opaquePass->AddInput("DepthStencilTexture");

	graph->AddNode(depthPass);
	graph->AddNode(opaquePass);

	graph->Link(depthPass, "DepthTexture", opaquePass, "DepthStencilTexture");

	auto* edges = graph->GetNodeEdges(depthPass);


	return 0;
}