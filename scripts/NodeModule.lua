local api = open_NodeLib()

local Node = {}
local Node.mt = {}

function Node.new(name)
	local p = api.Create(name)
	local n = { _node = p}
	setmetatable(n, Node.mt)
	return n
end

function Node.mt:GetName()
	return api.GetName(self._node)
end

return Node