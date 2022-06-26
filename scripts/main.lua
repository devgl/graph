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


