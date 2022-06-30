local api = open_FieldLib()
local field = {}
local mt = {
    __index = field
}

function field:getName()
    return api.GetName(self._field)
end

function field:setFormat(formatName)
    api.SetFormat(self._field, formatName)
end

function field:getFormat()
    return api.GetFormat(self._field)
end

function field:setType(typeName)
    api.SetType(self._field, typeName)
end

function field:getType()
    return api.GetType(self._field)
end

return function (f)
    return setmetatable({ _field = f }, mt)
end