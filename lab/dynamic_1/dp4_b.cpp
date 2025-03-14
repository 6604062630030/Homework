#include <bits/stdc++.h>

using namespace std;

int G(int n, map<int, int> &mem) {
  if (n == 0) return 0;
  if (n == 1 || n == 2) return 1;

  if (mem.find(n) == mem.end()) {
    mem[n] = G(n - 1, mem) + G(n - 2, mem) - G(n - 3, mem);
  }

  return mem[n];
}

int main() {

  int n, k;
  cin >> n;

  map<int, int> mem;

  cout << G(n, mem);

  return 0;
}