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

function node:addOutput(name)
	return Field(api.AddOutput(self._node, name))
end

function node:destroy()
	api.Destroy(self._node)
end

return function(name)
	return setmetatable({ _node = api.Create(name) }, mt)
end