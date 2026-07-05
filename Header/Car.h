//
// Created by PAYAM RAYANE on 7/4/2026.
//

#ifndef RAYLIB_TEST_CAR_H
#define RAYLIB_TEST_CAR_H


class Car {
    private:
        float speed ;
        float acceleration ;
        float deceleration ;
        float maxSpeed ;
        float x , y ,rotation;
        float rotationSpeed;
    public:
        Car();
        void setSpeed(float speed);
        float getSpeed();
        float getAcceleration();
        float getDeceleration();
        void setX(float x);
        void setY(float y);
        void setRotation(float rotation);
        float getX();
        float getY();
        float getRotation();
        float getRotationSpeed();
};


#endif //RAYLIB_TEST_CAR_H