/* MIT License
 *
 * Copyright (c) 2021 Brighton Sikarskie
 *  
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
