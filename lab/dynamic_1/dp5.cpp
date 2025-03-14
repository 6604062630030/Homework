#include <bits/stdc++.h>

using namespace std;

int func(int n, map<int, int> &mem) {
  if (n <= 2) return 1;

  if (mem.find(n) == mem.end()) {
    mem[n] = (3 * func(n - 1, mem)) + (2 * func(n - 2, mem));
  }

  return mem[n];
}

int main() {

  int n;
  cin >> n;

  map<int, int> mem;
  cout << func(n + 1, mem);

  return 0;
}