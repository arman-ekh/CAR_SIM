#include "raylib.h"
#include <cmath>
#include <string>
#include <algorithm>

#include "Header/Car.h"

#define RAD_TO_DEG (180.0f / 3.14159265358979323846f)

void draw_wheels(Car car, Rectangle &right_wheel, Rectangle &left_wheel);

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "CAR_SIM");
    SetTargetFPS(60);

    Car car;
    float dt;


    Rectangle rectangle;
    rectangle.width = 60;
    rectangle.height = 100;

    Rectangle right_wheel;
    Rectangle left_wheel;
    right_wheel.width = 6;
    right_wheel.height = 10;

    left_wheel.width = 6;
    left_wheel.height = 10;





    double change_angle_speed = 40;

    while (!WindowShouldClose()) {
        dt = GetFrameTime();
        BeginDrawing();

        if (IsKeyDown(KEY_W)) {
            car.set_long_force(car.get_long_force() + car.acceleration*dt);
        }else if (IsKeyDown(KEY_S)) {
            car.set_long_force(car.get_long_force()-car.deceleration*dt);
        }

        if (IsKeyDown(KEY_A)) {
            car.set_wheel_rotation(car.get_wheel_rotation() - change_angle_speed * dt);
        }else if (IsKeyDown(KEY_D)) {
            car.set_wheel_rotation(car.get_wheel_rotation() + change_angle_speed * dt);
        }

        if (IsKeyPressed(KEY_SPACE)) {
            car.set_is_drifting(!car.get_is_drifting());
        }

        std::string wheel_rotation = "wheel_rotation: " + std::to_string(car.get_wheel_rotation());
        std::string car_rotation = "car_rotation: " + std::to_string(car.get_car_rotation());
        std::string long_force = "long force: " + std::to_string(car.get_long_force());

        DrawText(wheel_rotation.c_str(),0 , 0 ,20 , BLACK);
        DrawText(car_rotation.c_str(),0 , 20 ,20 , BLACK);
        DrawText(long_force.c_str(),0 , 40 ,20 , BLACK);

        car.update_car(dt);
        rectangle.x = car.get_x();
        rectangle.y = car.get_y();
        DrawRectanglePro(rectangle , (Vector2){30,50} , car.get_car_rotation() , RED);

        draw_wheels(car, right_wheel, left_wheel);

        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
void draw_wheels(Car car, Rectangle &right_wheel, Rectangle &left_wheel) {
    float halfLength = 25.0f;
    float halfWidth = 40.0f;

    float angle = car.get_car_rotation() * PI / 180.0f;


    float fx = cos(angle);
    float fy = sin(angle);


    float rx = -sin(angle);
    float ry = cos(angle);

    right_wheel.x = car.get_x()
                    + fx * halfLength
                    + rx * halfWidth;

    right_wheel.y = car.get_y()
                    + fy * halfLength
                    + ry * halfWidth;
    left_wheel.x = car.get_x()
                   - fx * halfLength
                   + rx * halfWidth;

    left_wheel.y = car.get_y()
                   - fy * halfLength
                   + ry * halfWidth;

    DrawRectanglePro(right_wheel , (Vector2){3 , 5} ,car.get_car_rotation() +  car.get_wheel_rotation() , BLACK);
    DrawRectanglePro(left_wheel , (Vector2){3 , 5} ,car.get_car_rotation() +  car.get_wheel_rotation() , BLACK);
}
