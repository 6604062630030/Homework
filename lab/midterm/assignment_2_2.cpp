#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int binarySearch(int *arr, int l, int r, int target) {
  int mid = (l + r) / 2;

  if (l > r) {
    return -1;
  }

  if (target == arr[mid]) {
    return mid;
  }
  else if (target < arr[mid]) {
    return binarySearch(arr, l, mid - 1, target);
  }
  else {
    return binarySearch(arr, mid + 1, r, target);
  }
}

int main() {

  int n, k, match, temp, min = 100000;
  unordered_map<int, int> pair;
  cin >> n >> k;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  for (int i = 0; i < n; i++) {
    match = k - arr[i];
    temp = binarySearch(arr, 0, n - 1, match);
    if (temp != -1) {
      pair[arr[i]] = arr[temp];
    }
  }

  for (auto couple : pair) {
    if (couple.first > couple.second && couple.first - couple.second < min) {
      min = couple.first - couple.second;
    }
    else if (couple.first < couple.second && couple.second - couple.first < min) {
      min = couple.second - couple.first;
    }
  }

  cout << min;

  return 0;
}
