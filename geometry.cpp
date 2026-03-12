#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Define PI for calculations
const double PI = acos(-1.0);

void calculateAreaPerimeter() {
    int choice;
    cout << "\n--- Area & Perimeter ---\n";
    cout << "1. Circle\n2. Rectangle\nSelect shape: ";
    cin >> choice;

    if (choice == 1) {
        double r;
        cout << "Enter radius: ";
        cin >> r;
        cout << "Area = " << PI * r * r << "\n";
        cout << "Perimeter (Circumference) = " << 2 * PI * r << "\n";
    } else if (choice == 2) {
        double l, w;
        cout << "Enter length and width: ";
        cin >> l >> w;
        cout << "Area = " << l * w << "\n";
        cout << "Perimeter = " << 2 * (l + w) << "\n";
    } else {
        cout << "Invalid choice.\n";
    }
}

void calculateVolumeSurfaceArea() {
    int choice;
    cout << "\n--- Volume & Surface Area ---\n";
    cout << "1. Sphere\n2. Cylinder\nSelect shape: ";
    cin >> choice;

    if (choice == 1) {
        double r;
        cout << "Enter radius: ";
        cin >> r;
        cout << "Volume = " << (4.0 / 3.0) * PI * pow(r, 3) << "\n";
        cout << "Surface Area = " << 4 * PI * pow(r, 2) << "\n";
    } else if (choice == 2) {
        double r, h;
        cout << "Enter radius and height: ";
        cin >> r >> h;
        cout << "Volume = " << PI * pow(r, 2) * h << "\n";
        cout << "Surface Area = " << 2 * PI * r * h + 2 * PI * pow(r, 2) << "\n";
    } else {
        cout << "Invalid choice.\n";
    }
}

void calculatePythagorean() {
    double a, b;
    cout << "\n--- Pythagorean Theorem ---\n";
    cout << "Enter the lengths of the two legs (a and b): ";
    cin >> a >> b;
    double hypotenuse = sqrt(a * a + b * b);
    cout << "The hypotenuse (c) is = " << hypotenuse << "\n";
}

void calculateTrigFunctions() {
    double degrees;
    cout << "\n--- Trigonometric Functions ---\n";
    cout << "Enter an angle in degrees: ";
    cin >> degrees;

    // C++ trig functions require radians
    double radians = degrees * (PI / 180.0);

    cout << fixed << setprecision(4);
    cout << "sin(" << degrees << ") = " << sin(radians) << "\n";
    cout << "cos(" << degrees << ") = " << cos(radians) << "\n";
    cout << "tan(" << degrees << ") = " << tan(radians) << "\n";
}

int main() {
    int mainChoice;

    do {
        cout << "\n========== MATH MULTI-TOOL ==========\n";
        cout << "1. Area and Perimeter (2D)\n";
        cout << "2. Volume and Surface Area (3D)\n";
        cout << "3. Pythagorean Theorem\n";
        cout << "4. Trigonometric Functions\n";
        cout << "5. Exit\n";
        cout << "======================================\n";
        cout << "Select an operation (1-5): ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: calculateAreaPerimeter(); break;
            case 2: calculateVolumeSurfaceArea(); break;
            case 3: calculatePythagorean(); break;
            case 4: calculateTrigFunctions(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid selection. Please try again.\n";
        }
    } while (mainChoice != 5);

    return 0;
}
