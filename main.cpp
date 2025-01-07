#include <iostream>
#include <raylib.h>

using namespace std;

int main () {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int SNAKE_SIZE = 20;
    const int INITIAL_SNAKE_LENGTH = 5;

    // Vector2 are a struct that contains two floats: x and y
    // Struct Vector2 { float x; float y; }
    Vector2 snake[100]; // Array to store snake segments
    int snakeLength = INITIAL_SNAKE_LENGTH;
    Vector2 food;
    Vector direction = {1,0}; // Initial direction: right

    cout << "Hello World" << endl;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game!");
    SetTargetFPS(60);

    // while (WindowShouldClose() == false){
   
    //     ball_x += ball_speed_x;
    //     ball_y += ball_speed_y;
    //     cout << ball_x << " " << ball_y << endl;

    //     // first condition is for the right of the screen, second condition is for the left of the screen
    //     if(ball_x + ball_radius >= SCREEN_WIDTH || ball_x - ball_radius <= 0)
    //     {
    //         ball_speed_x *= -1;
    //     }

    //     // first condition is for the bottom of the screen, second condition is for the top of the screen
    //     if(ball_y + ball_radius >= SCREEN_HEIGHT || ball_y - ball_radius <= 0)
    //     {
    //         ball_speed_y *= -1;
    //     }
        
    //     BeginDrawing();
    //         ClearBackground(BLACK);
    //         Draw(ball_x,ball_y,ball_radius, WHITE);
    //     EndDrawing();
    // }
    for (int i = 0; i < snakeLength; i++){
        snake[i] = {SCREEN_WIDTH / 2 - i * SNAKE_SIZE, SCREEN_HEIGHT / 2}; // Initial position explanation: x = center of the screen, y = center of the screen (x,y) 
    }
    // Generate first food position
    food = {GetRandomValue(0, SCREEN_WIDTH / SNAKE_SIZE - 1) * SNAKE_SIZE, 
            GetRandomValue(0, SCREEN_HEIGHT / SNAKE_SIZE - 1) * SNAKE_SIZE};
    // food initial value explained: x = random value between 0 and screen width divided by snake size - 1, y = random value between 0 and screen height divided by snake size - 1

    while(!WindowShouldClise()){
        // Check user input
        if(IsKeyPressed(KEY_RIGHT) && direction.x == 0) direction = {1,0};
        if(IsKeyPressed(KEY_LEFT) && direction.x == 0) direction = {0,1};
        if(IsKeyPressed(KEY_UP) && direction.y == 0) direction = {1, 0};
        if(IsKeyPressed(KEY_DOWN) && direction.y == 0) direction = {0,1};

        // Update the snake postion
        for(int i = snakeLength - 1; i > 0; i--){
            snake[i] = snake[i - 1];
        }
        
    }
}