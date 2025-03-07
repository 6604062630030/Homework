// check circle for directed graph with dfs
#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
  unordered_map<int, vector<int>> g;

  bool ccHelp(int curr, set<int> visited, set<int> recursionStack) { // dfs
    if (recursionStack.count(curr)) return true; // cycle for sure
    if (visited.count(curr)) return false; // not sure if cycle but already visited

    recursionStack.insert(curr);
    visited.insert(curr);

    for (int i : g[curr]) {
      if (ccHelp(curr, visited, recursionStack)) {
        return true;
      }
    }
    recursionStack.erase(curr); // Remove from recursion stack after processing
    return false;
  }

public:
  void addEdge(int src, int dest) {
    g[src].push_back(dest);
  }

  bool checkCycle() {
    set<int> visited;
    set<int> recursionStack;

    for (auto pair : g) {
      int curr = pair.first;
      if (!visited.count(curr)) { // check if runing through all vertex
        if (ccHelp(curr, visited, recursionStack)) {
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