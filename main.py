import raylib as rl
from vmath import color32

rl.InitWindow(800, 450, "raylib [core] example - basic window")

RAYWHITE = color32(34, 34, 34, 255)
LIGHTGRAY = color32(200, 200, 200, 255)

while not rl.WindowShouldClose():
    rl.BeginDrawing()
    rl.ClearBackground(RAYWHITE)
    rl.DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY)
    rl.EndDrawing()

rl.CloseWindow()
