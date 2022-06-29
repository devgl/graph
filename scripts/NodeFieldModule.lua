local api = open_FieldLib()
local field = {}
local mt = {
    __index = field
}

function field:getName()
    return api.GetName(self._field)
end

return function (f)
    return setmetatable({ _field = f }, mt)
end