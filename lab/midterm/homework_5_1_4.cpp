#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void search(vector<int> &arr, int M, int K) {
  sort(arr.begin(), arr.end());

  int i = 0;
  while (i < arr.size() - 1) {
    if (abs(arr[i] - M) < abs(arr[i + 1] - M)) {
      break;
    }
    i++;
  }

  int left = i - 1, right = i;

  while ((right - left) <= K) {
    cout << left << " " << right << endl;
    if (left >= 0 && (right >= arr.size() || abs(arr[left] - M) <= abs(arr[right] - M))) {
      left--;
    }
    else {
      right++;
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int M, K;
  cin >> M >> K;

  search(arr, M, K);

  return 0;
}
