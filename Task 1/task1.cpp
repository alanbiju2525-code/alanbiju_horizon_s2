#include <iostream>
#include <cmath>
using namespace std;

class Rover {
private:
    double x1, y1, x2, y2;
    double initialVelocity, acceleration, maxSpeed;
    double distance;

public:

    // Input coordinates
    void getCoordinates() {
        cout << "Enter origin (x1 y1): ";
        cin >> x1 >> y1;

        cout << "Enter destination (x2 y2): ";
        cin >> x2 >> y2;
    }

    // Input motion parameters
    void getMotionParameters() {
        cout << "Enter initial velocity: ";
        cin >> initialVelocity;

        cout << "Enter acceleration: ";
        cin >> acceleration;

        cout << "Enter maximum speed: ";
        cin >> maxSpeed;
    }

    // Calculate distance
    void calculateDistance() {
        distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    // Calculate time
    double calculateTime() {

        double timeToMax = (maxSpeed - initialVelocity) / acceleration;

        if (timeToMax < 0)
            timeToMax = 0;

        // Distance covered during acceleration
        double distAccel = (initialVelocity * timeToMax) +
                           (0.5 * acceleration * pow(timeToMax, 2));

        double time = 0;

        if (distAccel >= distance) {
            // Rover doesn't reach max speed

            double a = 0.5 * acceleration;
            double b = initialVelocity;
            double c = -distance;

            double D = b * b - 4 * a * c;

            time = (-b + sqrt(D)) / (2 * a);

        } else {
            // Rover reaches max speed, then moves at constant speed

            double remainingDist = distance - distAccel;
            double timeConst = remainingDist / maxSpeed;

            time = timeToMax + timeConst;
        }

        return time;
    }

    // Display result
    void display(double time) {
        cout << "\nDistance to destination: " << distance << " meters" << endl;
        cout << "Time required: " << time << " seconds" << endl;
    }
};

int main() {
    Rover r;

    r.getCoordinates();
    r.calculateDistance();

    r.getMotionParameters();

    double time = r.calculateTime();

    r.display(time);

    return 0;
}