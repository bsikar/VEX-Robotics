#include <array>
#include <vector>
#include <cmath>

using std::array;
using std::vector;

typedef array<double, 2> point;

class bezier {
private:
    point P0;
    point P1;
    point P2;
    point P3;
    vector<double> data;

    point pointAdd(point p1, point p2) {
        return {p1[0] + p2[0], p1[1] + p2[1]};
    }

    point pointTimesScalar(point p, double k) {
        return {p[0] * k, p[1] * k};
    }

    point getQuadraticBezier(double t) {
        point point1 = pointTimesScalar(P0, 1 - (2 * t) + (t * t));
        point point2 = pointTimesScalar(P1, 2 * t * (1 - t));
        point point3 = pointTimesScalar(P2, t * t);

        return pointAdd(pointAdd(point1, point2), point3);
    }

    point getCubicBezier(double t) {
        point B1 = getQuadraticBezier(P0, P1, P2, t);
        point B2 = getQuadraticBezier(P1, P2, P3, t);

        return pointAdd(pointTimesScalar(B1, 1 - t), pointTimesScalar(B2, t));
    }

public:
    bezier(point P0, point P1, point P2, point P3) {
       this->P0 = P0;
       this->P1 = P1;
       this->P2 = P2;
       this->P3 = P3;
    }

    vector<point> getData(int p) {
        vector<point> cords {};

        for (int t = 0; t < p; ++t) {
            point c = getCubicBezier((double)t / (double)p);
            cords.push_back(c);
        }

        return cords;
    }
};
