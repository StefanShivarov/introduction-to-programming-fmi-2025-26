#include <iostream>
using namespace std;

double getPerimeter(double a1, double b1, double a2, double b2, double a3, double b3) {
    return sqrt(pow(a1 - a3, 2) + pow(b1 - b3, 2)) + sqrt(pow(a2 - a3, 2) + pow(b2 - b3, 2)) + sqrt(pow(a1 - a2, 2) + pow(b1 - b2, 2));
}
double getArea(double a1, double b1, double a2, double b2, double a3, double b3) {
    return sqrt(getPerimeter(a1, b1, a2, b2, a3, b3) / 2 * (getPerimeter(a1, b1, a2, b2, a3, b3) / 2 - sqrt(pow(a1 - a3, 2) + pow(b1 - b3, 2))) * (getPerimeter(a1, b1, a2, b2, a3, b3) / 2 - sqrt(pow(a2 - a3, 2) + pow(b2 - b3, 2))) * (getPerimeter(a1, b1, a2, b2, a3, b3) / 2 - sqrt(pow(a1 - a2, 2) + pow(b1 - b2, 2))));
}
bool isInsideCircleWithRadius(double a1, double b1, double a2, double b2, double a3, double b3, double r) {
    return r >= sqrt(pow(a1, 2) + pow(b1, 2)) && r >= sqrt(pow(a2, 2) + pow(b2, 2)) && r >= sqrt(pow(a3, 2) + pow(b3, 2));
}
int main() {
    double a1, b1, a2, b2, a3, b3, r;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> r;
    cout << getPerimeter(a1, b1, a2, b2, a3, b3) << endl;
    cout << getArea(a1, b1, a2, b2, a3, b3) << endl;
    if (isInsideCircleWithRadius(a1, b1, a2, b2, a3, b3, r))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}