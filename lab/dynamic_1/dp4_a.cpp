#include <bits/stdc++.h>

using namespace std;

int F(int n, int k, map<pair<int, int>, int> &mem) {
  if (k == 0 || k == 1 || n == k) {
    return 1;
  }

  if (mem.find(make_pair(n, k)) == mem.end()) {
    mem[make_pair(n, k)] = F(n - 1, k, mem) + F(n - 1, k - 2, mem);
  }

  return mem[make_pair(n, k)];

}

int main() {

  map<pair<int, int>, int> mem;

  int n, k;
  cin >> n >> k;

  cout << F(n, k, mem);


  return 0;
}