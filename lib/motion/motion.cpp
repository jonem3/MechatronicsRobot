#include <motion.h>

void motion::setEncoders(int countL, int countR)
{
    leftEnc.setEncoders(countL);
    rightEnc.setEncoders(countR);
}

void motion::setup()
{
    leftMot.setup();
    rightMot.setup();
}

void motion::moveToAngle(double leftMotAngle, double rightMotAngle)
{
    double leftAngle, rightAngle;
    int startTime = millis();
    int elapsedTime = 0;
    int counter = 0;
    do
    {
        counter++;
        leftAngle = leftEnc.readAngle();
        rightAngle = rightEnc.readAngle();
        double errorL = leftMotAngle - leftAngle;
        double errorR = rightMotAngle - rightAngle;
        leftMot.moveMotor(errorL * AngleKp);
        rightMot.moveMotor(errorR * AngleKp);
         elapsedTime = (millis() - startTime);
        
    } while (leftAngle != leftMotAngle && rightAngle != rightMotAngle && elapsedTime <= 2000);
    leftMot.moveMotor(0);
    rightMot.moveMotor(0);
}

double motion::getAvgEnc()
{
    double avgEnc = (-leftEnc.readAngle() + rightEnc.readAngle()) / 2;
    return avgEnc;
}

float motion::speedController(float currentSpeed, float targetSpeed, int motor)
{
    float error = targetSpeed - currentSpeed;
    float input = error * Kp + cumError[motor] * Ki;
    cumError[motor] += error;
    if (cumError[motor] > (100 / Ki))
    {
        cumError[motor] = (100 / Ki);
    }
    else if (cumError[motor] < -(100 / Ki))
    {
        cumError[motor] = -(100 / Ki);
    }

    return input;
}

void motion::setMotorSpeed(float left, float right)
{
    double leftSpeed = leftEnc.getSpeed();
    double rightSpeed = rightEnc.getSpeed();
    float leftInput;
    float rightInput;
    if (left != 0)
    {
        leftInput = speedController(leftSpeed, left, 0);
    }
    else
    {
        leftInput = 0;
    }
    if (right != 0)
    {
        rightInput = speedController(rightSpeed, right, 1);
    }
    else
    {
        rightInput = 0;
    }

    leftMot.moveMotor(leftInput);
    rightMot.moveMotor(rightInput);
}

void motion::rotateAngle(float degrees)
{
    float rotationPercentage = degrees / 360;           // How many rotations of the robot
    float toTravel = robotCir * rotationPercentage;     // How far a wheel needs to travel to acheive this
    float numRotations = toTravel / wheelCircumference; // Number of rotations of a wheel needed
    float rotationDegrees = numRotations * 360;         // Conversion to degrees
    double leftAngle = leftEnc.readAngle();
    double rightAngle = rightEnc.readAngle();
    moveToAngle(leftAngle + rotationDegrees, rightAngle - rotationDegrees);
}

float motion::getDistanceTravelled()
{
    // Returns distance travelled in mm
    float currentLEnc = leftEnc.readAngle();
    float currentREnc = rightEnc.readAngle();
    float avgEnc = (currentLEnc + currentREnc) / 2;
    float numRotations = avgEnc / 360;
    return (numRotations * wheelCircumference);
}

void motion::resetEncoders()
{
    leftEnc.resetEncCount();
    rightEnc.resetEncCount();
}

void motion::turnOnTheBreaks(){
    leftMot.brake();
    rightMot.brake();
}