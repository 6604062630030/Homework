#include <iostream>

using namespace std;

void printSol(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i];
  }
  cout << endl;
}

void genBinary(int *arr, int l, int r) {
  if (l == r) {
    printSol(arr, r);
  }
  else {
    arr[l] = 0;
    genBinary(arr, l + 1, r);
    arr[l] = 1;
    genBinary(arr, l + 1, r);
  }
}

void genbi(int *arr, int l, int r) {
  if (l == r) {
    printSol(arr, r);
  }
  else {
    arr[l] = 0;
    genbi(arr, l + 1, r);
    arr[l] = 1;
    genbi(arr, l + 1, r);
  }
}

int main() {
  int n = 4;
  int arr[n];

  genBinary(arr, 0, n);
}