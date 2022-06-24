local tb = open_GraphLib()

local NodeTable = open_NodeLib()
NodeTable.mt = 
{ 
	__index = function(tb, key) 
		return function(t, ...) 
			print(...)
			NodeTable[key](t._pNode, ...)
		end
	end
}

function NodeTable.new(name)
	local tb = {_pNode = NodeTable.Create(name)}
	setmetatable(tb, NodeTable.mt)
	return tb
end

local dummyNode = NodeTable.new("dummy")
dummyNode:AddInput("hehe")



