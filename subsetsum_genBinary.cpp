#include <iostream>

using namespace std;

void subsetsum(int *arr, int *marker, int n, int sum) {
  int sumcheck = 0;
  for (int i = 0;i < n; i++) {
    if (marker[i] == 1) {
      sumcheck += arr[i];
    }
  }

  if (sumcheck == sum) {
    for (int i = 0;i < n; i++) {
      if (marker[i] == 1) {
        cout << arr[i] << " ";
      }
    }
    cout << endl;
  }

}

void genBinary(int *arr, int *marker, int l, int r, int sum) {
  if (l == r) {
    subsetsum(arr, marker, r, sum);
  }
  else {
    marker[l] = 0;
    genBinary(arr, marker, l + 1, r, sum);
    marker[l] = 1;
    genBinary(arr, marker, l + 1, r, sum);
  }
}

int main() {

  int n = 5;
  int arr[n] = { 1, 2, 3, 4, 5 };
  int marker[n];
  int sum = 7;

  genBinary(arr, marker, 0, n, sum);

  return 0;
}