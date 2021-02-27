#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H

#include "math.h"
#include "../src/robotconfig.h"

using namespace vex;

class RobotState {
    private:
        double leftReader;
        double rightReader;
        const double wheelCircumference = 12.57;
        double avgRead;
        double avgReadPrev;
        double gyrot;
        double totaldist;
        struct Pos {
            double x;
            double y;
            double facing;
        } pos;
    
    public:
        RobotState() {
            leftReader = 0;
            rightReader = 0;
            avgRead = 0;
            avgReadPrev = 0;
            gyrot = 0;
            totaldist = 0;
            pos.x = pos.y = pos.facing = 0;
        }

        void Calculate(double lenc, double renc, double gyr) {
            double ldist = lenc * wheelCircumference;
            double rdist = renc * wheelCircumference;
            gyrot = gyr;
            avgRead = (ldist + rdist) / 2.0;

            pos.x += (avgRead - avgReadPrev) * cos(gyrot * (M_PI / 180));
            pos.y += (avgRead - avgReadPrev) * sin(gyrot * (M_PI / 180));

            pos.facing = inert.rotation(degrees);
            avgReadPrev = avgRead;
        }

        void reset() {
            avgReadPrev = 0;
        }

        double getX() {
            return pos.x;
        }

        double getY() {
            return pos.y;
        }

        double getAvg() {
            return avgReadPrev;
        }
        
        double getGyro() {
            return pos.facing;
        }
};

#endif
