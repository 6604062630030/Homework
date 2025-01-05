#include <iostream>

using namespace std;

int partition(int *arr, int l, int r) {
  int p = arr[l];
  int i = l;
  int j = r + 1;

  while (true) {
    do {
      i++;
    } while (arr[i] < p);

    do {
      j--;
    } while (arr[j] > p);

    swap(arr[i], arr[j]);

    if (i >= j) {
      break;
    }
  }
  swap(arr[i], arr[j]);
  swap(arr[l], arr[j]);

  return j;
}

void quickSort(int *arr, int l, int r) {
  if (l < r) {
    int s = partition(arr, l, r);

    quickSort(arr, l, s - 1);
    quickSort(arr, s + 1, r);
  }
}

int main() {

  int len;
  cin >> len;
  int *arr = new int[len];

  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }

  quickSort(arr, 0, len - 1);

  for (int i = 0; i < len;i++) {
    cout << arr[i] << " ";
  }
  delete arr;

  return 0;
}