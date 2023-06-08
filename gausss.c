#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define EPSILON 0.00001

void gauss_elimination(int n, double a[n][n], double b[n], double x[n]) {
    printf("\n------------------------------------------------------------------------\n");
    printf("Finding roots by Gauss-Elimination Method");
    printf("\n------------------------------------------------------------------------\n");
  for (int k = 0; k < n - 1; k++) {
    for (int i = k + 1; i < n; i++) {
      double factor = a[i][k] / a[k][k];
      b[i] -= factor * b[k];
      for (int j = k + 1; j < n; j++) {
        a[i][j] -= factor * a[k][j];
      }
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    double sum = 0;
    for (int j = i + 1; j < n; j++) {
      sum += a[i][j] * x[j];
    }
    x[i] = (b[i] - sum) / a[i][i];
  }
  for (int i = 0; i < n; i++) {
    printf("x%d = %lf\n",i+1,x[i]);
  }
}

void gauss_jordon(int n, double a[n][n], double b[n], double x[n]) {
    printf("\n------------------------------------------------------------------------\n");
    printf("Finding roots by Gauss-Jordon Method");
    printf("\n------------------------------------------------------------------------\n");
  for (int k = 0; k < n; k++) {
    double pivot = a[k][k];
    b[k] /= pivot;
    for (int j = 0; j < n; j++) {
      a[k][j] /= pivot;
    }

    for (int i = 0; i < n; i++) {
      if (i != k) {
        double factor = a[i][k];
        b[i] -= factor * b[k];
        for (int j = 0; j < n; j++) {
          a[i][j] -= factor * a[k][j];
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    x[i] = b[i];
  }
  for (int i = 0; i < n; i++) {
    printf("x%d = %lf\n",i+1,x[i]);
  }
}

int main() {
  int n = 3;
  printf("\n------------------------------------------------------------------------\nEquations are-->\n\nx1 + 3x2 +2x3 = 17\nx1 + 2x2 +3x3 = 16\n2x1 - x2 + 4x3 = 13\n");
  do
  {
    
  double a[3][3] = {
    {1, 3, 2},
    {1, 2, 3},
    {2, -1, 4}
  };
  double b[3] = {17, 16, 13};
  double x[3];

  printf("\n------------------------------------------------------------------------\nEnter 1 for Gauss-Elimination Method\nEnter 2 for Gauss-Jordon Method\nEnter 3 to exit\n--> ");

  int choice;
  scanf("%d", &choice);

  if(choice==1) gauss_elimination(n,a,b,x);
  else if (choice==2) gauss_jordon(n,a,b,x);
  else if(choice==3) break;
  else printf("\nInvalid option choose one-->");
  } while (1);
  return 0;
}
