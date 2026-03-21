#include <iostream>
#include <cmath>
using namespace std;

class Rover {
private:
    double x1, y1, x2, y2;

public:
    void getCoordinates() {
        cout << "Enter origin (x1 y1): ";
        cin >> x1 >> y1;

        cout << "Enter destination (x2 y2): ";
        cin >> x2 >> y2;
    }

    double calculateDistance() {
        double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        return dist;
    }

    void displayDistance(double dist) {
        cout << "Distance to destination: " << dist << " meters" << endl;
    }
};

int main() {
    Rover r;

    r.getCoordinates();

    double distance = r.calculateDistance();

    r.displayDistance(distance);

    return 0;
}