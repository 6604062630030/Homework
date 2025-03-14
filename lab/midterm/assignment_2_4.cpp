#include <iostream>

using namespace std;

int main() {

  int n, min = 100000, max = 0, temp;
  cin >> n;

  int time[n][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> temp;
      time[i][j] = temp;
      if (temp < min) {
        min = temp;
      }
      if (temp > max) {
        max = temp;
      }
    }
  }

  int arr[max + 1];
  for (int i = 0; i < max + 1; i++) {
    arr[i] = 0;
  }

  int a, b;
  for (int i = 0; i < n; i++) {
    a = time[i][0];
    b = time[i][1];
    for (int j = a; j < b + 1;j++) {
      arr[j] += 1;
    }
  }

  n = max + 1;
  int index = 0;
  max = 0;
  bool continuity = false;
  for (int i = min; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
      index = i;
      continuity = true;
    }
    if (continuity && arr[i] < max) {
      continuity = false;
    }
    if (arr[i] == max && continuity) {
      temp = i;
    }
  }
  cout << index << " " << temp << " " << max << " ";

  return 0;
}