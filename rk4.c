#include <stdio.h>
#include <math.h>

#define X_FINAL 0.8
#define H 0.2
#define EPSILON 0.00001

double f(double x, double y) {
  return x * y;
}

int main() {
  double x = 0, y = 2;

  while (fabs(x - X_FINAL) > EPSILON) {
    double k1 = H * f(x, y);
    double k2 = H * f(x + H / 2, y + k1 / 2);
    double k3 = H * f(x + H / 2, y + k2 / 2);
    double k4 = H * f(x + H, y + k3);

    y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    x = x + H;
  }

  printf("\n------------------------------------------------------------------------\ny(%.2lf) = %.5lf\n\nComputed y(0.8) using 4th order R-K method correct to five decimal places\n------------------------------------------------------------------------\n", X_FINAL, y);

  return 0;
}
