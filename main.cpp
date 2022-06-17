#include "Graph.hpp"
#include "Node.hpp"

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

	return 0;
}