//
// Created by PAYAM RAYANE on 7/4/2026.
//

#ifndef RAYLIB_TEST_CAR_H
#define RAYLIB_TEST_CAR_H


class Car {
    private:
        float long_velocity , lat_velocity ;
        float acceleration ;
        float deceleration ;
        float maxSpeed ;
        float x , y ,rotation;
        float rotationSpeed;
        float wheel_angle;
        float C_drag;//air friction ratio
        float C_rr;//Rolling Resistance of car tire ratio
        float maxEngineForce , engineForce;
        float Lf , Lr;// distance between the center of mass and front/back wheel
        float Cr , Cf;//Cornering stiffness front/rear
        float mass , width , height;
        float i;//Rotational Inertia
        float getDragForce();
        float getRrForce();

        float geLatVelocityFrontWheel();
        float geLatVelocityBackWheel();
        float getSlipAngleFront();
        float getSlipAngleBack();
        float getLatForceFront();
        float getLatForceBack();
        float getLongForce();
    public:
        Car();
        float getAcceleration();
        float getDeceleration();
        void setX(float x);
        void setY(float y);
        void setRotation(float rotation);
        float getX();
        float getY();
        float getRotation();
        float getLongAcc();
        float getLatAcc();
        void setLatVelocity(float lat_velocity);
        void setLongVelocity(float long_velocity);
        void setEngineForce(float engineForce);
        float getEngineForce();
        float getWheelAngle();
        void setWheelAngle(float wheel_angle);
        float getRotationSpeed();
        void setRotationSpeed(float rotation_speed);
        float getAngularAcceleration();
        float getLongVelocity();
        float getLatVelocity();



};


#endif //RAYLIB_TEST_CAR_H