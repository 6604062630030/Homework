#include <bits/stdc++.h>

using namespace std;

int C(int n, int k, map<pair<int, int>, int> &mem) {
  if (k == 0 || (n == k)) {
    return 1;
  }

  if (mem.find(make_pair(n, k)) == mem.end()) {
    mem[make_pair(n, k)] = C(n - 1, k - 1, mem) + C(n - 1, k, mem);
  }

  return mem[make_pair(n, k)];
}

int main() {

  int n, k;
  cin >> n >> k;

  map<pair<int, int>, int> mem;
  cout << C(n, k, mem);

  return 0;
}
