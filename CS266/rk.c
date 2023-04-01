#include <stdio.h>

double f(double t, double y) {
    return -1*y*y + 5;  // Define the function f(t, y)
}

// double rk2(double t, double y, double h) {
//     double k1 = h * f(t, y);
//     double k2 = h * f(t + h, y + k1);
//     return y + (k1 + k2) / 2;  // Runge-Kutta 2nd order method
// }

double rk4(double t, double y, double h) {
    double k1 = h * f(t, y);
    double k2 = h * f(t + h / 2, y + k1 / 2);
    double k3 = h * f(t + h / 2, y + k2 / 2);
    double k4 = h * f(t + h, y + k3);
    return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;  // Runge-Kutta 4th order method
}

int main() {
    double t0 = 0;  // Initial time
    double y0 = 1;  // Initial value
    double h = 0.5;  // Step size
    double tn = 2000;  // Final time
    double t = t0;
    double y = y0;

    printf("t = %.1f, y = %.6f\n", t, y);  // Print initial values

    while (t < tn) {  // Loop over time steps
        y = rk4(t, y, h);  // Use Runge-Kutta 4th order method
        t += h;
        printf("t = %.6f, y = %.6f\n", t, y);  // Print current values
    }

    return 0;
}

