#ifndef RAYLIB_TEST_CAR_H
#define RAYLIB_TEST_CAR_H


class Car {
    private:
        float x , y;
        float long_force;
        float car_rotation;
        float wheel_rotation;
        float drag;
        bool going_reverse;
        bool is_drifting = false;






    public:
        const float max_long_force =40;
        const float acceleration = 20;
        const float deceleration = 20;
        const float max_wheel_rotation = 50;

        Car();
        void set_car_position(float x, float y);
        float get_y();
        float get_x();
        float get_long_force();
        void set_long_force(float long_force);
        void update_car(float dt);
        float get_car_rotation();
        void set_wheel_rotation(float wheel_rotation);
        float get_wheel_rotation();
        bool get_is_drifting();
        void set_is_drifting(bool is_drifting);
};


#endif //RAYLIB_TEST_CAR_H