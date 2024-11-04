import raylib as rl

rl.InitWindow(800, 450, "raylib [core] example - basic window")

RAYWHITE = rl.Color(34, 34, 34, 255)
LIGHTGRAY = rl.Color(200, 200, 200, 255)

while not rl.WindowShouldClose():
    rl.BeginDrawing()
    rl.ClearBackground(RAYWHITE)
    rl.DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY)
    rl.EndDrawing()

rl.CloseWindow()
