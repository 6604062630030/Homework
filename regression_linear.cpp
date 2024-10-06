#include <iostream>
#include <math.h>

using namespace std;

class linear {
private:
  int n;
  double *x;
  double *y;

  double A[2][2];
  double *X;
  double Y[2];

  double powerSum(double *arr, double power) {
    double sum=0;
    for(int i=0; i<n; i++) {
      sum += pow(arr[i], power);
    }
    return sum;
  }

  double mixSum(double *arr1, double *arr2) {
    double sum=0;
    for(int i=0; i<n; i++) {
      sum += arr1[i]*arr2[i];
    }
    return sum;
  }

  void cramer_2x2() {
    double detA = det_2x2(A);
    double x1[2][2] = {{Y[0],A[0][1]},{Y[1],A[1][1]}};
    double x2[2][2] = {{A[0][0],Y[0]},{A[1][0],Y[1]}};
    double detX1 = det_2x2(x1);
    double detX2 = det_2x2(x2);
    X = new double[2];
    X[0] = detX1/detA;
    X[1] = detX2/detA;
  }

  double det_2x2(double arr[2][2]) {
    return arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
  }

public:
  linear(int n, double *x, double *y) {
    this->n = n;
    this->x = new double[n];
    this->y = new double[n];
    
    for (int i = 0; i < n; i++) {
      this->x[i] = x[i];
      this->y[i] = y[i];
    }

    A[0][0] = n;
    A[0][1] = powerSum(this->x, 1);
    A[1][0] = A[0][1];
    A[1][1] = powerSum(this->x, 2);

    Y[0] = powerSum(this->y, 1);
    Y[1] = mixSum(this->x, this->y);

    cramer_2x2();
  }

  double f(int x) {
    return X[0] + X[1]*x;
  }

};
////////////////////////////////////////////////////////////////
class multipleLinear {
private:
  int n;
  double *x1;
  double *x2;
  double *x3;
  double *y1;

  double A[4][4];
  double *X;
  double Y[4];

  double powerSum(double *arr, double power) {
    double sum=0;
    for(int i=0; i<n; i++) {
      sum += pow(arr[i], power);
    }
    return sum;
  }

  double mixSum(double *arr1, double *arr2) {
    double sum=0;
    for(int i=0; i<n; i++) {
      sum += arr1[i]*arr2[i];
    }
    return sum;
  }

  void cramer_4x4() {
    double detA = det_4x4(A);
    //cout << detA;
    double x1[4][4] = {{Y[0],A[0][1],A[0][2],A[0][3]},{Y[1],A[1][1],A[1][2],A[1][3]},{Y[2],A[2][1],A[2][2],A[2][3]},{Y[3],A[3][1],A[3][2],A[3][3]}};
    double x2[4][4] = {{A[0][0],Y[0],A[0][2],A[0][3]},{A[1][0],Y[1],A[1][2],A[1][3]},{A[2][0],Y[2],A[2][2],A[2][3]},{A[3][0],Y[3],A[3][2],A[3][3]}};
    double x3[4][4] = {{A[0][0],A[0][1],Y[0],A[0][3]},{A[1][0],A[1][1],Y[1],A[1][3]},{A[2][0],A[2][1],Y[2],A[2][3]},{A[3][0],A[3][1],Y[3],A[3][3]}};
    double x4[4][4] = {{A[0][0],A[0][1],A[0][2],Y[0]},{A[1][0],A[1][1],A[1][2],Y[1]},{A[2][0],A[2][1],A[2][2],Y[2]},{A[3][0],A[3][1],A[3][2],Y[3]}};
    double detX1 = det_4x4(x1);
    double detX2 = det_4x4(x2);
    double detX3 = det_4x4(x3);
    double detX4 = det_4x4(x4);

    X = new double[4];
    X[0] = detX1/detA;
    X[1] = detX2/detA;
    X[2] = detX3/detA;
    X[3] = detX4/detA;

    cout << "f(x) = " << X[0] << " + (" << X[1] << ")*x1" << " + (" << X[2] << ")*x2" << " + (" << X[3] << ")*x3" ;
  }

  double det_4x4(double arr[4][4]) {
    double tempA[3][3] = {{arr[1][1],arr[1][2],arr[1][3]},{arr[2][1],arr[2][2],arr[2][3]},{arr[3][1],arr[3][2],arr[3][3]}};
    double tempB[3][3] = {{arr[1][0],arr[1][2],arr[1][3]},{arr[2][0],arr[2][2],arr[2][3]},{arr[3][0],arr[3][2],arr[3][3]}};
    double tempC[3][3] = {{arr[1][0],arr[1][1],arr[1][3]},{arr[2][0],arr[2][1],arr[2][3]},{arr[3][0],arr[3][1],arr[3][3]}};
    double tempD[3][3] = {{arr[1][0],arr[1][1],arr[1][2]},{arr[2][0],arr[2][1],arr[2][2]},{arr[3][0],arr[3][1],arr[3][2]}};

    return arr[0][0]*det_3x3(tempA) - arr[0][1]*det_3x3(tempB) + arr[0][2]*det_3x3(tempC) - arr[0][3]*det_3x3(tempD);
  }

  double det_3x3(double arr[3][3]) {
    return (arr[0][0]*arr[1][1]*arr[2][2] + arr[0][1]*arr[1][2]*arr[2][0] + arr[0][2]*arr[1][0]*arr[2][1]) 
         - (arr[2][0]*arr[1][1]*arr[0][2] + arr[2][1]*arr[1][2]*arr[0][0] + arr[2][2]*arr[1][0]*arr[0][1]);
  }

public:
  multipleLinear(int n, double *x1, double *x2, double *x3, double *y1) {
    this->n = n;
    this->x1 = new double[n];
    this->x2 = new double[n];
    this->x3 = new double[n];
    this->y1 = new double[n];

    for (int i = 0; i < n; i++) {
      this->x1[i] = x1[i];
      this->x2[i] = x2[i];
      this->x3[i] = x3[i];
      this->y1[i] = y1[i];
    }

    A[0][0] = n;
    A[0][1] = powerSum(x1,1);
    A[0][2] = powerSum(x2,1);
    A[0][3] = powerSum(x3,1);

    A[1][0] = powerSum(x1,1);
    A[1][1] = mixSum(x1,x1);
    A[1][2] = mixSum(x1,x2);
    A[1][3] = mixSum(x1,x3);

    A[2][0] = powerSum(x2,1);
    A[2][1] = mixSum(x2,x1);
    A[2][2] = mixSum(x2,x2);
    A[2][3] = mixSum(x2,x3);

    A[3][0] = powerSum(x3,1);
    A[3][1] = mixSum(x3,x1);
    A[3][2] = mixSum(x3,x2);
    A[3][3] = mixSum(x3,x3);

    Y[0] = powerSum(y1,1);
    Y[1] = mixSum(y1,x1);
    Y[2] = mixSum(y1,x2);
    Y[3] = mixSum(y1,x3);

    cramer_4x4();
  }

};

int main() {
  int n = 9;
  double x[9] = {10,15,20,30,40,50,60,70,80};
  double y[9] = {5,9,15,18,22,30,35,38,43};
  int value = 65;

  linear l(n, x, y);
  //cout << l.f(65);

  //multipleLinear
  n = 7;
  double x1[7] = {1,0,2,3,4,2,1};
  double x2[7] = {0,1,4,2,1,3,6};
  double x3[7] = {1,3,1,2,5,3,4};
  double y1[7] = {4,-5,-6,0,-1,-7,-20};

  multipleLinear ml(n,x1,x2,x3,y1);
}