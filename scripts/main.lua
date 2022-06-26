local graphLib = open_GraphLib()
local nodeLib = open_NodeLib();
local fieldLib = open_FieldLib();

nodeLib.mt = {
	__index = function (tb, key)
		return function(tb, ...)
			nodeLib[key](tb._node, ...)
		end
	end
}

nodeLib.new = function ( name )
	local p = nodeLib.Create(name)
	local n = { _node = p}
	setmetatable(n, nodeLib.mt)
	return n
end

local Node = {}
function Node.new(name)
	local p = nodeLib.Create(name)
	local n = { _node = p }
	setmetatable(n, Node)
	return n
end

function Node:GetName()
	return nodeLib.GetName(self._node)
end

local n1 = nodeLib.new("node_01")
print("table n1 : ", n1)
print(n1:GetName())



<<<<<<< HEAD
=======
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



>>>>>>> a317181bbc5832d7a667302feab95b0ce6a02329
