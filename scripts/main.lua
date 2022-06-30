local Node = require("NodeModule")
local n1 = Node("node01")
print(n1:getName())

local f1 = n1:addInput("n1_input01")
f1:setType("field 1 type")
f1:setFormat("field 1 format")
print(f1:getName(), f1:getType(), f1:getFormat())



local n2 = Node("node02")
print(n2:getName())