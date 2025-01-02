#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

  int n, temp;
  unordered_map<int, int> intersect;
  cin >> n;

  int *arr1 = new int[n];
  int *arr2 = new int[n];
  for (int i = 0;i < n; i++) {
    cin >> temp;
    arr1[i] = temp;
    if (intersect.find(temp) == intersect.end()) {
      intersect[temp] = 1;
    }
    else {
      intersect[temp]++;
    }
  }

  for (int i = 0;i < n; i++) {
    cin >> temp;
    arr2[i] = temp;
    if (intersect.find(temp) == intersect.end()) {
      intersect[temp] = 1;
    }
    else {
      intersect[temp]++;
    }
  }

  // copy to vector
  vector<int> dupe;
  vector<int> all;
  for (auto it = intersect.begin(); it != intersect.end(); it++) {
    if (it->second > 1) {
      dupe.push_back(it->first);
    }
  }
  for (auto pair : intersect) {
    all.push_back(pair.first);
  }

  // printing
  for (int i = dupe.size() - 1; i >= 0; i--) {
    cout << dupe[i] << " ";
  }
  cout << endl;

  for (int i = all.size() - 1; i >= 0; i--) {
    cout << all[i] << " ";
  }

  return 0;
}