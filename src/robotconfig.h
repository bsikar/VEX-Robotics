#ifndef ROBOTCONFIG_H
#define ROBOTCONFIG_H

#include "v5_vcs.h"
using namespace vex;

competition Competition;
brain Brain;

controller Controller1 = controller(primary);
inertial inert = inertial(PORT4);
motor elevator = motor(PORT2, ratio18_1, true);
motor lfdrive = motor(PORT9, ratio18_1, true);
motor lbdrive = motor(PORT7, ratio18_1, false);
motor rbdrive = motor(PORT10, ratio18_1, true);
motor rfdrive = motor(PORT8, ratio18_1, false);
motor rintake = motor(PORT6, ratio6_1, false);
motor lintake = motor(PORT5, ratio6_1, true);
motor roller = motor(PORT3, ratio18_1, true);
optical opti = optical(PORT18);

#endif
