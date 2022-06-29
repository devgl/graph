local Field = require("NodeFieldModule")

local api = open_NodeLib()
local node = {}
local mt = {
    __index = node
}

function node:getName()
	return api.GetName(self._node)
end

function node:addInput(name)
	return Field(api.AddInput(self._node, name))
end

return function(name)
	return setmetatable({ _node = api.Create(name) }, mt)
end