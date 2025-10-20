local player = {
    x = 0,
    y = 0,
    speed = 500,
    radius = 50
}

local image = momentum.graphics.newImage("image.jpg")

momentum.window.setTargetFPS(60)
print(momentum.lua.version())

return function()
    momentum.graphics.beginDrawing()
    momentum.graphics.clearBackground(0, 0, 0, 255)

    local direction = {
        x = 0,
        y = 0
    }
    local deltaTime = momentum.time.getDelta()

    if momentum.input.isKeyDown(87) then
        direction.y = direction.y - 1
    end

    if momentum.input.isKeyDown(65) then
        direction.x = direction.x - 1
    end

    if momentum.input.isKeyDown(83) then
        direction.y = direction.y + 1
    end

    if momentum.input.isKeyDown(68) then
        direction.x = direction.x + 1
    end

    if math.abs(direction.x) + math.abs(direction.y) ~= 0 then
        local length = math.sqrt(direction.x * direction.x + direction.y * direction.y)
        direction.x = direction.x / length
        direction.y = direction.y / length
    end

    direction.x = direction.x
    direction.y = direction.y
    player.x = player.x + direction.x * deltaTime * player.speed
    player.y = player.y + direction.y * deltaTime * player.speed

    momentum.graphics.drawCircle(player.x, player.y, player.radius, 255, 255, 255, 255)
    momentum.graphics.drawText(tostring(1 / momentum.time.getDelta()), momentum.input.getMouseX(), momentum.input.getMouseY(), 20, 255, 255, 0, 255)

    if momentum.input.isMouseDown(0) then
        momentum.graphics.drawRectangle(20, 20, 20, 20, 0, 0, 255, 255)
    else
        momentum.graphics.drawRectangle(20, 20, 20, 20, 0, 255, 255, 255)
    end

    momentum.graphics.drawImage(image, 100, 100, 255, 255, 255, 255)
    momentum.graphics.drawText(tostring(momentum.lua.memory()), 0, 0, 50, 255, 0, 0, 255)

    momentum.graphics.endDrawing()
end
