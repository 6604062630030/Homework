#include <iostream>
#include <algorithm>
using namespace std;

void goodPermute(int *arr, int start, int end) { // not work
  if (start == end) {
    for (int i = 0; i < end; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = start; i < end; i++) {
    swap(arr[start], arr[i]);
    sort(arr + start + 1, arr + end);
    goodPermute(arr, start + 1, end);
  }
}

int main() {
  int n = 4;
  int arr[] = { 1, 2, 3, 4 };

  goodPermute(arr, 0, n);

  return 0;
}
