#include "robotconfig.h"

using namespace vex;

void autonomous();
void usercontrol();

int main() {
    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);
}

void autonomous() {
    inert.calibrate();
    task::sleep(2000);
}

void usercontrol() {
    for (;;) {
        rfdrive.spin(directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), velocityUnits::pct);
        rbdrive.spin(directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), velocityUnits::pct);
        lfdrive.spin(directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), velocityUnits::pct);
        lbdrive.spin(directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), velocityUnits::pct);

        if (Controller.ButtonL1.pressing()) {
            elevator.spin(directionType::fwd, 100, velocityUnits::pct);
            roller.spin(directionType::fwd, 100, velocityUnits::pct);
        } else if (Controller.ButtonL2.pressing()) {
            elevator.spin(directionType::rev, 100, velocityUnits::pct);
           roller.spin(directionType::rev, 100, velocityUnits::pct);
        } else {
            roller.stop(brakeType::brake);
            elevator.stop(brakeType::brake);
        }

        if (Controller.ButtonR1.pressing()) {
            lintake.spin(directionType::rev, 100, velocityUnits::pct);
            rintake.spin(directionType::rev, 100, velocityUnits::pct);
        } else if (Controller.ButtonR2.pressing()) {
            lintake.spin(directionType::fwd, 100, velocityUnits::pct);
            rintake.spin(directionType::fwd, 100, velocityUnits::pct);
        } else {
            lintake.stop(brakeType::brake);
            rintake.stop(brakeType::brake);
        }

        wait(15, msec);
    }
}
