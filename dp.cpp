#include <bits/stdc++.h>

using namespace std;

int Fac(int n, map<int, int> mem) {
  if (n == 0) return 1;

  if (mem.find(n) == mem.end()) {
    mem[n] = n * Fac(n - 1, mem);
  }

  return mem[n];
}

bool subSetSum(int n, int k, int *arr, map<pair<int, int>, int> &mem) {
  if (n == 0 || k < 0) return false;
  if (k == 0) return true;

  if (mem.find(make_pair(n, k)) == mem.end()) {
    mem[make_pair(n, k)] = subSetSum(n - 1, k, arr, mem) || subSetSum(n - 1, k - arr[n], arr, mem);
  }

  return mem[make_pair(n, k)];
}

int main() {

  // int n;
  // cin >> n;

  // map<int, int> mem;
  // cout << Fac(n, mem);

  int n, k;
  cin >> n >> k;
  int arr[n + 1];
  arr[0] = 0;
  for (int i = 1;i <= n;i++) {
    cin >> arr[i];
  }
  map<pair<int, int>, int> mem;
  cout << (subSetSum(n, k, arr, mem) ? "T" : "F");

  return 0;
}
