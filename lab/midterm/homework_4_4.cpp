#include <iostream>

using namespace std;

int *distributionCounting(int *arr, int n) {
  int l = INT_MAX;
  int u = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (arr[i] < l) {
      l = arr[i];
    }
    if (arr[i] > u) {
      u = arr[i];
    }
  }

  int *D = new int[u - l];
  int *S = new int[n - 1];

  for (int j = 0; j <= u - l; j++) D[j] = 0;
  for (int i = 0; i <= n - 1; i++) D[arr[i] - l] = D[arr[i] - l] + 1;
  for (int j = 1; j <= u - l; j++) D[j] = D[j - 1] + D[j];
  for (int i = n - 1; i >= 0; i--) {
    int j = arr[i] - l;
    S[D[j] - 1] = arr[i];
    D[j] = D[j] - 1;
  }
  return S;
}

int main() {

  int len;
  cin >> len;
  int *arr = new int[len];

  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }

  int *sorted = distributionCounting(arr, len);

  for (int i = 0; i < len;i++) {
    cout << sorted[i] << " ";
  }
  delete arr;

  return 0;
}