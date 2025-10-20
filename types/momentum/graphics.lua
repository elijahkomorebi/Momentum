---@meta

---@class momentum.graphics
momentum.graphics = {}

---@class MomentumImage

function momentum.graphics.beginDrawing() end

function momentum.graphics.endDrawing() end

---@param r number
---@param g number
---@param b number
---@param a number
function momentum.graphics.clearBackground(r, g, b, a) end

---@param path string
---@return MomentumImage
function momentum.graphics.newImage(path) end

---@param image MomentumImage
function momentum.graphics.deleteImage(image) end

function momentum.graphics.push() end

function momentum.graphics.pop() end

---@param x number
---@param y number
function momentum.graphics.translate(x, y) end

---@param a number
function momentum.graphics.rotate(a) end

---@param x number
---@param y number
function momentum.graphics.scale(x, y) end

---@param text string
---@param x number
---@param y number
---@param s number
---@param r number
---@param g number
---@param b number
---@param a number
function momentum.graphics.drawText(text, x, y, s, r, g, b, a) end

---@param x number
---@param y number
---@param s number
---@param r number
---@param g number
---@param b number
---@param a number
function momentum.graphics.drawCircle(x, y, s, r, g, b, a) end

---@param x number
---@param y number
---@param w number
---@param h number
---@param r number
---@param g number
---@param b number
---@param a number
function momentum.graphics.drawRectangle(x, y, w, h, r, g, b, a) end

---@param image MomentumImage
---@param x number
---@param y number
---@param r number
---@param g number
---@param b number
---@param a number
function momentum.graphics.drawImage(image, x, y, r, g, b, a) end
