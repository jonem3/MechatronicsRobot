
    public:
        motor(int speed, bool ai1, bool ai2, bool standby);
        void stop();
        void reverse();
        void adjustspeed(int pwm);
};