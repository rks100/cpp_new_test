#include <iostream>
#include <cmath> // Include this header to use sqrt
using namespace std;

class Airplane {
public:
    double wingArea;
    double liftCoefficient;
    double airDensity;
    double velocity;

    void calculateLift() const {
        double lift = 0.5 * liftCoefficient * airDensity * velocity * velocity * wingArea;
        cout << "The lift force is: " << lift << " Newtons" << endl <<endl ;
    }

    void calculateWingArea() const {
        double lift, wingArea;
        cout << "Enter the lift force (in Newtons): ";
        cin >> lift;
        wingArea = lift / (0.5 * liftCoefficient * airDensity * velocity * velocity);
        cout << "The wing area is: " << wingArea << " square meters" << endl <<endl ;
    }

    void calculateLiftCoefficient() const {
        double lift, liftCoefficient;
        cout << "Enter the lift force (in Newtons): ";
        cin >> lift;
        liftCoefficient = lift / (0.5 * airDensity * velocity * velocity * wingArea);
        cout << "The lift coefficient is: " << liftCoefficient << endl <<endl ;
    }

    void calculateAirDensity() const {
        double lift, airDensity;
        cout << "Enter the lift force (in Newtons): ";
        cin >> lift;
        airDensity = lift / (0.5 * liftCoefficient * velocity * velocity * wingArea);
        cout << "The air density is: " << airDensity << " kg/m^3" << endl <<endl ;
    }

    void calculateVelocity() const {
        double lift, velocity;
        cout << "Enter the lift force (in Newtons): ";
        cin >> lift;
        velocity = sqrt(lift / (0.5 * liftCoefficient * airDensity * wingArea));
        cout << "The velocity is: " << velocity << " m/s" << endl <<endl ;
    }
};

int main() {
    Airplane plane;
    char choice;

    cout << "Choose what to calculate: \n1. Lift (L)\n2. Wing Area (A)\n3. Lift Coefficient (C_L)\n4. Air Density (ρ)\n5. Velocity (v)\n";
    cin >> choice;

    if (choice == '1') {
        cout << "Enter wing area (m²): ";
        cin >> plane.wingArea;
        cout << "Enter lift coefficient: ";
        cin >> plane.liftCoefficient;
        cout << "Enter air density (kg/m³): ";
        cin >> plane.airDensity;
        cout << "Enter velocity (m/s): ";
        cin >> plane.velocity;
        plane.calculateLift();
    } else if (choice == '2') {
        cout << "Enter lift coefficient: ";
        cin >> plane.liftCoefficient;
        cout << "Enter air density (kg/m³): ";
        cin >> plane.airDensity;
        cout << "Enter velocity (m/s): ";
        cin >> plane.velocity;
        plane.calculateWingArea();
    } else if (choice == '3') {
        cout << "Enter wing area (m²): ";
        cin >> plane.wingArea;
        cout << "Enter air density (kg/m³): ";
        cin >> plane.airDensity;
        cout << "Enter velocity (m/s): ";
        cin >> plane.velocity;
        plane.calculateLiftCoefficient();
    } else if (choice == '4') {
        cout << "Enter wing area (m²): ";
        cin >> plane.wingArea;
        cout << "Enter lift coefficient: ";
        cin >> plane.liftCoefficient;
        cout << "Enter velocity (m/s): ";
        cin >> plane.velocity;
        plane.calculateAirDensity();
    } else if (choice == '5') {
        cout << "Enter wing area (m²): ";
        cin >> plane.wingArea;
        cout << "Enter lift coefficient: ";
        cin >> plane.liftCoefficient;
        cout << "Enter air density (kg/m³): ";
        cin >> plane.airDensity;
        plane.calculateVelocity();
    } else {
        cout << "Invalid choice." << endl <<endl ;
    }

    return 0;
}