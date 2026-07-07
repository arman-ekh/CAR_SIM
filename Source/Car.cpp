#include "../Header/Car.h"
#include <cmath>

#define PI 3.14159265358979323846f

Car::Car() {
    this->long_velocity = 0.0f;
    this->lat_velocity = 0.0f;
    this->acceleration = 200.0f;
    this->deceleration = 400.0f;
    this->x = 200.0f;
    this->y = 200.0f;
    this->rotation = 0.0f;
    this->rotationSpeed = 0.0f;
    this->maxEngineForce = 800.0f;
    this->engineForce = 0.0f;
    this->C_drag = 0.2f;
    this->C_rr = 0.01f;
    this->Lf = 1.5;
    this->Lr = 1;
    this->wheel_angle = 0.0f;
    this->Cr = 65.0f;
    this->Cf = 100.0f;
    this->width = 1.0f;
    this->height = 4.8f;
    this->mass = 10.0f;
    this->i = 60.0f;
    this->max_steer = 0.85f;
}



void Car::setRotation(float rotation) {
    if (rotation > 2.0f * PI) {
        this->rotation = rotation - (2.0f * PI);
    } else if (rotation < 0.0f) {
        this->rotation = rotation + (2.0f * PI);
    } else {
        this->rotation = rotation;
    }
}

float Car::getRotation() { return this->rotation; }

void Car::setEngineForce(float engineForce) {
    if (engineForce > maxEngineForce) this->engineForce = maxEngineForce;
    else if (engineForce < -maxEngineForce / 2.0f) this->engineForce = -maxEngineForce / 2.0f;
    else this->engineForce = engineForce;
}

float Car::getEngineForce() { return this->engineForce; }


void Car::setWheelAngle(float wheel_angle) {
    if (wheel_angle > max_steer) this->wheel_angle = max_steer;
    else if (wheel_angle < -max_steer) this->wheel_angle = -max_steer;
    else this->wheel_angle = wheel_angle;
}

float Car::getWheelAngle() { return this->wheel_angle; }

float Car::getLongVelocity() {
    return long_velocity;
}
void Car::setLongVelocity(float long_velocity) {
    this->long_velocity = long_velocity;
}
float Car::getLatVelocity() {return  lat_velocity;}
void Car::setLatVelocity(float lat_v) { this->lat_velocity = lat_v; }


float Car::getDragForce() {
    return -1.0f * C_drag * long_velocity * std::abs(long_velocity);
}

float Car::getRrForce() {
    return -1.0f * C_rr * getLongVelocity();
}

float Car::getLongForce() {
    float long_force = getRrForce() + getDragForce() + engineForce;
    if (std::abs(long_force) < 3 ) {
        return 0;
    }
    return long_force;
}

float Car::geLatVelocityFrontWheel() {
    return getLatVelocity() + Lf * rotationSpeed;
}

float Car::geLatVelocityBackWheel() {
    return getLatVelocity() - Lr * rotationSpeed;
}


float Car::getSlipAngleFront() {
    float v_long = getLongVelocity();
    if (std::abs(v_long) < 0.5f) return 0.0f;
    float v_lat = geLatVelocityFrontWheel();
    return std::atan2(v_lat, v_long) - wheel_angle;
}

float Car::getSlipAngleBack() {
    float v_long = getLongVelocity();
    if (std::abs(v_long) < 0.5f) return 0.0f;
    float v_lat = geLatVelocityBackWheel();
    return std::atan2(v_lat, v_long);
}

float Car::getLatForceFront() {
    return -1.0f * getSlipAngleFront() * Cf;
}

float Car::getLatForceBack() {
    return -1.0f * getSlipAngleBack() * Cr;
}

float Car::getAngularAcceleration() {
     return (getLatForceFront() * std::cos(wheel_angle) * Lf - getLatForceBack() * Lr) / i;
}

float Car::getLongAcc() {
   return (getLongForce() - getLatForceFront() * std::sin(wheel_angle)) / mass;
}

float Car::getLatAcc() {
    return (getLatForceBack() + getLatForceFront() * std::cos(wheel_angle)) / mass;
}

float Car::getRotationSpeed() { return this->rotationSpeed; }
void Car::setRotationSpeed(float rotation_speed) { this->rotationSpeed = rotation_speed; }

float Car::getX() { return this->x; }
void Car::setX(float x) { this->x = x; }
float Car::getY() { return this->y; }
void Car::setY(float y) { this->y = y; }
float Car::getAcceleration() { return this->acceleration; }
float Car::getDeceleration() { return this->deceleration; }