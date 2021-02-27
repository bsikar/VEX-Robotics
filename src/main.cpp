#include "math.h"
#include "robotconfig.h"
#include "robotstate.h"

using namespace vex;

const float slowDown = 0.8;

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
        rfdrive.spin(directionType::fwd, (Controller1.Axis3.value() - (slowDown * Controller1.Axis1.value())), velocityUnits::pct);
        rbdrive.spin(directionType::fwd, (Controller1.Axis3.value() - (slowDown * Controller1.Axis1.value())), velocityUnits::pct);
        lfdrive.spin(directionType::fwd, (Controller1.Axis3.value() + (slowDown * Controller1.Axis1.value())), velocityUnits::pct);
        lbdrive.spin(directionType::fwd, (Controller1.Axis3.value() + (slowDown * Controller1.Axis1.value())), velocityUnits::pct);
        opti.setLight(ledState::on);
        opti.setLightPower(100, pct);
        
        if (Controller1.ButtonL2.pressing()) {
            roller.setVelocity(100, percent);
            elevator.setVelocity(80, percent);
            if (opti.hue() > 50) {
                elevator.spin(fwd);
                roller.spin(reverse);
            } else {
                elevator.spin(forward);
                roller.spin(forward);
            }
            elevator.spin(forward);
            roller.spin(forward);
        } else if (Controller1.ButtonL1.pressing()) {
            elevator.spin(directionType::rev, 200, velocityUnits::pct);
            roller.spin(directionType::rev, 200, velocityUnits::pct);
        } else {
            roller.stop(brakeType::brake);
            elevator.stop(brakeType::brake);
        }
          
        if (Controller1.ButtonR1.pressing()) {
            lintake.spin(directionType::rev, 100, velocityUnits::pct);
            rintake.spin(directionType::rev, 100, velocityUnits::pct);
        } else if (Controller1.ButtonR2.pressing()) {
            lintake.spin(directionType::fwd, 100, velocityUnits::pct);
            rintake.spin(directionType::fwd, 100, velocityUnits::pct);
        } else {
            lintake.stop(brakeType::brake);
            rintake.stop(brakeType::brake);
        }
        wait(15, msec);
    }
}
