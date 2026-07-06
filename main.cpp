#include "raylib.h"
#include <cmath>
#include "Header/Car.h"

#define RAD_TO_DEG (180.0f / 3.14159265358979323846f)

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;



    InitWindow(screenWidth, screenHeight, "CAR_SIM");

    SetTargetFPS(60);
    Car car;

    float dt;

    Rectangle *rectangle = new Rectangle();
    rectangle->height = 60;
    rectangle->width = 100;

    while (!WindowShouldClose()) {
        dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (IsKeyDown(KEY_W)) {
            car.setEngineForce(car.getEngineForce() + car.getAcceleration() * dt);
        }else if (IsKeyDown(KEY_S)) {
            car.setEngineForce(car.getEngineForce() - car.getDeceleration() * dt);
        }else {
            car.setEngineForce(car.getEngineForce() * 0.9f);
        }
        if (IsKeyDown(KEY_A)) {
            car.setWheelAngle(car.getWheelAngle() - 4.0f * dt);
        }else if (IsKeyDown(KEY_D)) {
            car.setWheelAngle(car.getWheelAngle() + 4.0f * dt);
        }else {
            car.setWheelAngle(car.getWheelAngle() * 0.8f);
        }

        if (IsKeyDown(KEY_SPACE)) {
            car.setEngineForce(0);
        }

        car.setLongVelocity(car.getLongVelocity() + car.getLongAcc() * dt);
        car.setLatVelocity(car.getLatVelocity() + car.getLatAcc() * dt);

        car.setRotationSpeed(car.getRotationSpeed() + car.getAngularAcceleration()*dt );
        car.setRotation(car.getRotation() + car.getRotationSpeed()* dt);

        float v_x = car.getLongVelocity() * std::cos(car.getRotation()) - car.getLatVelocity() * std::sin(car.getRotation());
        float v_y = car.getLongVelocity() * std::sin(car.getRotation()) + car.getLatVelocity() * std::cos(car.getRotation());

        car.setX(car.getX() + (v_x * dt) * 20.0f);
        car.setY(car.getY() + (v_y * dt) * 20.0f);


        rectangle->x = car.getX();
        rectangle->y = car.getY();

        DrawRectanglePro(*rectangle, (Vector2){30 , 50} , car.getRotation() * RAD_TO_DEG, RED);




        EndDrawing();
    }





    CloseWindow();
    return 0;
}
