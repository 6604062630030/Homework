#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, target;
  int a, b;
  bool hasAns = false;
  unordered_map<int, int> match;
  cin >> n >> target;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] + arr[j] == target) {
        if (match.find(arr[i]) == match.end() && match.find(arr[j]) == match.end()) {
          hasAns = true;
          match[arr[i]] = arr[j];
          match[arr[i]] = arr[j];
          cout << arr[i] << " " << arr[j] << endl;
        }
      }
    }
  }

  if (!hasAns) {
    cout << -1;
  }
}
