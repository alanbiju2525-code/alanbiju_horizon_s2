#include <iostream>
#include <cmath>
using namespace std;

class Rover {
private:
    double x1, y1, x2, y2;
    double initialVelocity, acceleration, maxSpeed;
    double distance;

public:

    
    void getCoordinates() {
        cout << "Enter origin (x1 y1): ";
        cin >> x1 >> y1;

        cout << "Enter destination (x2 y2): ";
        cin >> x2 >> y2;
    }

    
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

    // Calculate time with error handling
    double calculateTime() {

        // --- Basic error checks ---
        if (maxSpeed <= 0) {
            cout << "Error: Max speed must be positive!" << endl;
            return -1;
        }

        if (acceleration == 0) {
            cout << "Error: Acceleration cannot be zero!" << endl;
            return -1;
        }

        if (distance < 0) {
            cout << "Error: Invalid distance!" << endl;
            return -1;
        }

        double timeToMax = (maxSpeed - initialVelocity) / acceleration;

        if (timeToMax < 0)
            timeToMax = 0;

        double distAccel = (initialVelocity * timeToMax) +
                           (0.5 * acceleration * pow(timeToMax, 2));

        double time = 0;

        if (distAccel >= distance) {

            double a = 0.5 * acceleration;
            double b = initialVelocity;
            double c = -distance;

            double D = b * b - 4 * a * c;

            if (D < 0) {
                cout << "Error: No real solution!" << endl;
                return -1;
            }

            time = (-b + sqrt(D)) / (2 * a);

        } else {
            // Constant speed phase

            if (maxSpeed == 0) {
                cout << "Error: Division by zero!" << endl;
                return -1;
            }

            double remainingDist = distance - distAccel;
            double timeConst = remainingDist / maxSpeed;

            time = timeToMax + timeConst;
        }

        return time;
    }

   
    void display(double time) {
        if (time >= 0) {
            cout << "\nDistance to destination: " << distance << " meters" << endl;
            cout << "Time required: " << time << " seconds" << endl;
        } else {
            cout << "Calculation failed due to invalid input." << endl;
        }
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