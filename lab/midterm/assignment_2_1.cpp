#include <iostream>

using namespace std;

void interpolationSearch(int *arr, int l, int r, int target) {
  int mid = l + (((target - arr[l]) * (r - l)) / (arr[r] - arr[l]));
  cout << mid << " ";

  if (l > r) {
    cout << "not found";
    return;
  }

  if (target == arr[mid]) {
    return;
  }
  else if (target < arr[mid]) {
    interpolationSearch(arr, l, mid - 1, target);
  }
  else {
    interpolationSearch(arr, mid + 1, r, target);
  }
}

int main() {

  int n, target;
  cin >> n >> target;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  interpolationSearch(arr, 0, n - 1, target);

  return 0;
}
