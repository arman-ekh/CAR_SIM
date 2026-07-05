#include "../Header/Car.h"

Car::Car() {
    this->speed = 0;
    this->acceleration = 10;
    this->deceleration = 20;
    this->maxSpeed = 150;
    this->x = 100;
    this->y = 200;
    this->rotation = 0;
    this->rotationSpeed = 80;
}

void Car::setSpeed(float speed) {
    if (speed > maxSpeed) {
        this->speed = maxSpeed;
    }
    else if (speed < 0) {
        this->speed = 0;
    }
    else {
        this->speed = speed;
    }
}

float Car::getSpeed() {
    return this->speed;
}
float Car::getAcceleration() {
    return this->acceleration;
}
float Car::getDeceleration() {
    return this->deceleration;
}

void Car::setX(float x) {
    this->x = x;
}
void Car::setY(float y) {
    this->y = y;
}
float Car::getX() {
    return this->x;
}
float Car::getY() {
    return this->y;
}

void Car::setRotation(float rotation) {
    if (rotation > 360) {
        this->rotation = rotation - 360;
    }else if (rotation < 0) {
        this->rotation = rotation + 360;
    }else {
        this->rotation = rotation;
    }

}

float Car::getRotation() {
    return this->rotation;
}

float Car::getRotationSpeed() {
    return this->rotationSpeed;
}
