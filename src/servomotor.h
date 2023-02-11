class ServoMotor{
    private:
    int pin;
    double angle;
    int pulseWidth;
    double maxAngle;
    double minAngle;
    const float pi = 3.142;
    Servo motor;
    public:
    ServoMotor(int servoPin, int pulse, double max, double min);
    void moveTo(double setAngle);
    double getAngle(); 
};

/*
Note: Servo motors are dumb
Conditional control will be done in the robot arm class
which is clever
*/