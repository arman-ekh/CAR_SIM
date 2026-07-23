#include "../Header/Car.h"

#include <cmath>


#define PI 3.14159265358979323846f

Car::Car() {
    this->x = 100;
    this->y = 100;
    this->long_force = 0;
    this->car_rotation = 0;
    this->wheel_rotation = 0;
    this->drag = 1;
    this->going_reverse = false;
}

float Car::get_long_force() {
    return long_force;
}

float Car::get_x() {
    return x;
}
float Car::get_y() {
    return y;
}

void Car::set_car_position(float x, float y) {
    this->x = x;
    this->y = y;
}

void Car::set_long_force(float long_force) {
    if (long_force < 0 && std::abs(long_force) > 10) {
        this->long_force = -10;
        return;
    }
    if (std::abs(long_force) > max_long_force) {
        this->long_force = max_long_force;
        return;
    }
    this->long_force = long_force;
}


float Car::get_car_rotation() {
    return car_rotation;
}

void Car::set_wheel_rotation(float wheel_rotation) {
    if (wheel_rotation > max_wheel_rotation) {
        this->wheel_rotation = max_wheel_rotation;
        return;
    }if (wheel_rotation < -max_wheel_rotation) {
        this->wheel_rotation = -max_wheel_rotation;
        return;
    }
    this->wheel_rotation = wheel_rotation;
}

float Car::get_wheel_rotation() {
    return wheel_rotation;
}


bool Car::get_is_drifting() {
    return is_drifting;
}

void Car::set_is_drifting(bool is_drifting) {
    this->is_drifting = is_drifting;
}

void Car::update_car(float dt) {
    this->y = y + long_force * std::cos(car_rotation * PI / 180);
    this->x = x - long_force * std::sin(car_rotation*PI / 180);
    this->long_force*=0.98;
    if (long_force < 0) {
        this->going_reverse =true;
    }else {
        this->going_reverse=false;
    }
    if (std::abs(long_force) > 1) {
        if (!is_drifting) {
            if (going_reverse) {
                this->car_rotation = car_rotation + ((0 - wheel_rotation*5) / drag)*dt;
            }else {
                this->car_rotation = car_rotation + ((0 + wheel_rotation*5) / drag)*dt;
            }
        }else {
            if (going_reverse) {
                this->car_rotation = car_rotation + ((0 - wheel_rotation*5) / (drag*3))*dt;
            }else {
                this->car_rotation = car_rotation + ((0 + wheel_rotation*5) / (drag*3))*dt;
            }
        }

    }
    this->wheel_rotation *= 0.98 ;
}
