#include <iostream>
#include <vector>
#include "bezier.cpp" // including because linking is cringe

using std::cout;

double radians(double x) {
    return x * 3.14159265 / 180;
}

int main() {
    double a1 = 0, a2 = 0;
    double n1 = 10, n2 = 10;
    double w1 = 0, w2 = 0;

    point P0 {a1, a2};
    point P1 {fabs(a1 + 10) * cos(radians(w1 - 90)) + a1, fabs(a2 + 10) * sin(radians(w1 + 90)) + a2};
    point P2 {fabs(n1) * cos(radians(w2 - 270)) + n1, fabs(n2) * sin(radians(w2 - 90)) + n2};
    point P3 {n1, n2};
    bezier curve = bezier(P0, P1, P2, P3);

    vector<point> cords = curve.getData(10);

    for (point p : cords) {
        cout << "[" << p[0] << ", " << p[1] << "]\n";
    }

    return 0;
}
