#include <iostream>
#include <cmath> // For sqrt function
#include <iomanip> // For setprecision

using namespace std;

// Function to check if three sides can form a triangle
bool isTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Function to determine the type of triangle
string triangleType(double a, double b, double c) {
    if (a == b && b == c) {
        return "Tam giac deu";
    }
    if (a == b || b == c || a == c) {
        return "Tam giac can";
    }
    if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
        return "Tam giac vuong";
    }
    return "Tam giac thuong";
}

// Function to calculate the area of a triangle using Heron's formula
double calculateArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    double a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    // Check if the sides can form a triangle
    if (!isTriangle(a, b, c)) {
        cout << "Khong phai tam giac" << endl;
    } else {
        // Determine the type of triangle
        string type = triangleType(a, b, c);
        double area = calculateArea(a, b, c);
        
        // Output the type and area of the triangle
        cout << type << ", dien tich = " << fixed << setprecision(2) << area << endl;
    }

    return 0;
}
