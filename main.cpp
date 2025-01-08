#include <iostream>
#include <raylib.h>

using namespace std;

int main () {

    // const values
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int SNAKE_SIZE = 20;
    const int INITIAL_SNAKE_LENGTH = 5;

    // Vector2 are a struct that contains two floats: x and y
    // Struct Vector2 { float x; float y; }
    Vector2 snake[100]; // Array to store snake segments
    int snakeLength = INITIAL_SNAKE_LENGTH;
    Vector2 food;
    Vector2 direction = {1, 0}; // Initial direction: right

    cout << "Hello World" << endl;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game!");
    SetTargetFPS(15);

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

    while(!WindowShouldClose()){
        // Check user input
        if(IsKeyPressed(KEY_RIGHT) && direction.x == 0) direction = {1,0};
        if(IsKeyPressed(KEY_LEFT) && direction.x == 0) direction = {-1,0};
        if(IsKeyPressed(KEY_UP) && direction.y == 0) direction = {0, -1};
        if(IsKeyPressed(KEY_DOWN) && direction.y == 0) direction = {0,1};

        // Update the snake postion
        for(int i = snakeLength - 1; i > 0; i--){
            snake[i] = snake[i - 1];
        }
        snake[0].x += direction.x * SNAKE_SIZE;
        snake[0].y += direction.y * SNAKE_SIZE;

        // Check for collisions with the border of window
        if(snake[0].x < 0 || snake[0].x >= SCREEN_WIDTH ||
           snake[0].y < 0 || snake[0].y >= SCREEN_HEIGHT) { 
                // Game Over, stops the game
                break; // leave while loop
        }

        for(int i = 1; i < snakeLength; i++) {
            // if statement to check if the snake head is in the same position as the snake body
            if(snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                // Gane Over
                break;
            }
        }

        // Check if the snake has eaten food
        if (snake[0].x == food.x && snake[0].y == food.y){
            snakeLength++;
            // Generate new food position
            food = {GetRandomValue(0, SCREEN_WIDTH / SNAKE_SIZE - 1) * SNAKE_SIZE, 
                    GetRandomValue(0, SCREEN_HEIGHT / SNAKE_SIZE - 1) * SNAKE_SIZE};
        }

        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0; i < snakeLength; i++) { 
            // DrawRectangleV(position, size, color) basic syntax
            DrawRectangleV(snake[i], {SNAKE_SIZE, SNAKE_SIZE}, GREEN);
        }
        DrawRectangleV(food, {SNAKE_SIZE, SNAKE_SIZE}, RED);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}