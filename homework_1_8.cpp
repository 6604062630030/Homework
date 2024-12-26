#include <iostream>

using namespace std;

int main() {

  int n, sum = 0, max = -100000;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) { //main index
    for (int j = 0; j < n; j++) {
      for (int k = i; k < n - j; k++) {
        //cout << "i=" << i << " j=" << j << " k=" << k << endl;
        sum += arr[k];
      }
      //cout << sum << endl;
      if (max < sum) {
        max = sum;
      }
      sum = 0;
    }
  }

  cout << max;

  return 0;
}