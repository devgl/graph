local api = open_NodeLib()

local Node = {}
function Node:GetName()
	return api.GetName(self._node)
end

local mt = {
	__index = Node
}

return function(name)
	local p = api.Create(name)
	local n = { _node = p}
	setmetatable(n, mt)
	return n
end