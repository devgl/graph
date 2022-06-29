local Node = require("NodeModule")
local n1 = Node("node01")
print(n1:getName())

local f1 = n1:addInput("n1_input01")
print(f1:getName())

local n2 = Node("node02")
print(n2:getName())