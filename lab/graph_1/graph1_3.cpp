// check circle for directed graph with dfs
#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
  unordered_map<int, vector<int>> g;

  bool ccHelp(int curr, int prev, set<int> &visited) { // dfs
    visited.insert(curr);

    for (auto neighbor : g[curr]) {
      if (!visited.count(neighbor)) {
        if (ccHelp(neighbor, curr, visited)) {
          return true;
        }
      }
      else if (neighbor != prev) {
        return true;
      }
    }
    return false;
  }

public:
  void addEdge(int src, int dest) {
    g[src].push_back(dest);
  }

  bool checkCycle() {
    set<int> visited;

    for (auto pair : g) {
      int curr = pair.first;
      if (!visited.count(curr)) {
        if (ccHelp(curr, -1, visited)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  int n;
  cin >> n;
  Graph g;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    int e = -1;
    while (e) {
      cin >> e;
      if (e != 0) {
        g.addEdge(v, e);
      }
    }
  }

  cout << g.checkCycle();

  return 0;
}