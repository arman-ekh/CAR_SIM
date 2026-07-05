#include "raylib.h"
#include <cmath>
#include "Header/Car.h"


int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;



    InitWindow(screenWidth, screenHeight, "CAR_SIM");

    SetTargetFPS(60);
    Car car;

    float dt;

    Rectangle *rectangle = new Rectangle();
    rectangle->height = 100;
    rectangle->width = 60;

    while (!WindowShouldClose()) {
        dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (IsKeyDown(KEY_W)) {
            car.setSpeed(car.getSpeed() + (car.getAcceleration() *dt));
        }
        if (IsKeyDown(KEY_S)) {
            car.setSpeed(car.getSpeed() - (car.getDeceleration() *dt));
        }
        if (IsKeyDown(KEY_A) && car.getSpeed() > 0) {
            car.setRotation(car.getRotation() - (car.getRotationSpeed()*dt));
        }
        if (IsKeyDown(KEY_D)&& car.getSpeed() > 0) {
            car.setRotation(car.getRotation() + (car.getRotationSpeed()*dt));
        }


        float radians = car.getRotation() * (PI / 180);
        float sine = sin(radians);
        float cosine = cos(radians);
        car.setY(car.getY() + car.getSpeed()*cosine);
        car.setX(car.getX() - car.getSpeed()*sine);

        rectangle->x = car.getX();
        rectangle->y = car.getY();

        DrawRectanglePro(*rectangle, (Vector2){30 , 0} , car.getRotation() , RED);




        EndDrawing();
    }





    CloseWindow();
    return 0;
}
