#include "../Header/Car.h"
#include <cmath>

#define PI 3.14159265358979323846f

Car::Car() {
    this->long_velocity = 0.0f;
    this->lat_velocity = 0.0f;
    this->acceleration = 1800.0f;
    this->deceleration = 3600.0f;
    this->maxSpeed = 150.0f;
    this->x = 200.0f;
    this->y = 200.0f;
    this->rotation = 0.0f;
    this->rotationSpeed = 0.0f;
    this->maxEngineForce = 12000.0f;
    this->engineForce = 0.0f;
    this->C_drag = 0.3f;
    this->C_rr = 12.0f;
    this->Lf = 1.2f;
    this->Lr = 1.2f;
    this->wheel_angle = 0.0f;
    this->Cr = 25000.0f;
    this->Cf = 25000.0f;
    this->width = 1.5f;
    this->height = 4.8f;
    this->mass = 1200.0f;
    this->i = (1.0f / 12.0f) * mass * (width * width + height * height);
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
    float max_steer = 0.6f;
    if (wheel_angle > max_steer) this->wheel_angle = max_steer;
    else if (wheel_angle < -max_steer) this->wheel_angle = -max_steer;
    else this->wheel_angle = wheel_angle;
}

float Car::getWheelAngle() { return this->wheel_angle; }

float Car::getLongVelocity() { return long_velocity; }
void Car::setLongVelocity(float long_velocity) { this->long_velocity = long_velocity; }
float Car::getLatVelocity() {return  lat_velocity;}
void Car::setLatVelocity(float lat_v) { this->lat_velocity = lat_v; }


float Car::getDragForce() {
    float velocity = getLongVelocity();
    return -1.0f * C_drag * velocity * std::abs(velocity);
}

float Car::getRrForce() {
    return -1.0f * C_rr * getLongVelocity();
}

float Car::getLongForce() {
    return getRrForce() + getDragForce() + engineForce;
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