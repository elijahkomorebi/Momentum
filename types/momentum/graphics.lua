---@meta

---@class momentum.graphics
momentum.graphics = {}

function momentum.graphics.beginDrawing() end

function momentum.graphics.endDrawing() end

---@param r number
---@param g number
---@param b number
---@param a number
function momentum.graphics.clearBackground(r, g, b, a) end

---@param text string
---@param x number
---@param y number
---@param r number
---@param g number
---@param b number
---@param a number
function momentum.graphics.drawText(text, x, y, r, g, b, a) end

---@param x number
---@param y number
---@param radius number
---@param r number
---@param g number
---@param b number
---@param a number
function momentum.graphics.drawCircle(x, y, radius, r, g, b, a) end
