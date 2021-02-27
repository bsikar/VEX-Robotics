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
