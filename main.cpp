#include "raylib.h"
#include <cmath>
#include <string>
#include <algorithm>

#include "Header/Car.h"

#define RAD_TO_DEG (180.0f / 3.14159265358979323846f)

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "CAR_SIM");
    SetTargetFPS(60);

    Car car;
    float dt;


    Rectangle rectangle;
    rectangle.width = 100;
    rectangle.height = 60;


    Rectangle wheel_rect;
    wheel_rect.width = 20;
    wheel_rect.height = 8;

    while (!WindowShouldClose()) {
        dt = GetFrameTime();


        if (IsKeyDown(KEY_W)) {
            car.setEngineForce(car.getEngineForce() + car.getAcceleration() * dt);
        } else if (IsKeyDown(KEY_S)) {
            car.setEngineForce(car.getEngineForce() - car.getDeceleration() * dt);
        } else {
            car.setEngineForce(car.getEngineForce() * 0.9f);
        }

        if (IsKeyDown(KEY_A)) {
            car.setWheelAngle(car.getWheelAngle() - 4.0f * dt);
        } else if (IsKeyDown(KEY_D)) {
            car.setWheelAngle(car.getWheelAngle() + 4.0f * dt);
        } else {
            car.setWheelAngle(car.getWheelAngle() * 0.95f);
        }

        if (IsKeyPressed(KEY_SPACE)) {
            car.setIsBreaking(!car.getIsBreaking());
        }


        if (car.getLongAcc() == 0) {
            if (std::abs(car.getLongVelocity()) < 5) {
                car.setLongVelocity(car.getLongVelocity() * 0.9f * dt);
            }
            if (std::abs(car.getLongVelocity()) < 0.5f) {
                car.setLongVelocity(0);
            }
        } else {
            car.setLongVelocity(car.getLongVelocity() + car.getLongAcc() * dt);
        }

        car.setLatVelocity(car.getLatVelocity() + car.getLatAcc() * dt);


        car.setRotationSpeed(car.getRotationSpeed() + car.getAngularAcceleration() * dt);
        car.setRotation(car.getRotation() + car.getRotationSpeed() * dt);


        float v_x = car.getLongVelocity() * std::cos(car.getRotation()) - car.getLatVelocity() * std::sin(car.getRotation());
        float v_y = car.getLongVelocity() * std::sin(car.getRotation()) + car.getLatVelocity() * std::cos(car.getRotation());

        car.setX(car.getX() + (v_x * dt) * 20.0f);
        car.setY(car.getY() + (v_y * dt) * 20.0f);


        BeginDrawing();
        ClearBackground(RAYWHITE);


        std::string carLongVelocity = "car long velocity: " + std::to_string(car.getLongVelocity());
        std::string latVelocity = "lat velocity: " + std::to_string(car.getLatVelocity());
        std::string carForce = "car long Force: " + std::to_string(car.getLongForce());
        std::string carX = "car x: " + std::to_string(car.getX());
        std::string carY = "car y: " + std::to_string(car.getY());
        std::string carIsBreaking = "car Break: " + std::to_string(car.getIsBreaking());

        DrawText(carLongVelocity.c_str(), 10, 10, 20, BLACK);
        DrawText(latVelocity.c_str(), 10, 35, 20, BLACK);
        DrawText(carForce.c_str(), 10, 60, 20, BLACK);
        DrawText(carX.c_str(), 10, 80, 20, BLACK);
        DrawText(carY.c_str(), 10, 100, 20, BLACK);
        DrawText(carIsBreaking.c_str(), 10, 120, 20, BLACK);


        rectangle.x = car.getX();
        rectangle.y = car.getY();

        DrawRectanglePro(rectangle, (Vector2){50, 30}, car.getRotation() * RAD_TO_DEG, RED);


        float car_rot = car.getRotation();
        float total_wheel_rot = (car.getRotation() + car.getWheelAngle()) * RAD_TO_DEG;


        float front_offset = 40.0f;
        float side_offset = 26.0f;


        float wheel_left_x = car.getX() + front_offset * std::cos(car_rot) - (-side_offset) * std::sin(car_rot);
        float wheel_left_y = car.getY() + front_offset * std::sin(car_rot) + (-side_offset) * std::cos(car_rot);
        wheel_rect.x = wheel_left_x;
        wheel_rect.y = wheel_left_y;
        DrawRectanglePro(wheel_rect, (Vector2){10, 4}, total_wheel_rot, BLACK);


        float wheel_right_x = car.getX() + front_offset * std::cos(car_rot) - side_offset * std::sin(car_rot);
        float wheel_right_y = car.getY() + front_offset * std::sin(car_rot) + side_offset * std::cos(car_rot);
        wheel_rect.x = wheel_right_x;
        wheel_rect.y = wheel_right_y;
        DrawRectanglePro(wheel_rect, (Vector2){10, 4}, total_wheel_rot, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}