#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
  map<int, vector<int>> g;
  int nVertex;

  void dfs(int neighbor, int currStep, int maxStep, set<int> &visited) {
    if (currStep != maxStep) {
      currStep++;
      visited.insert(neighbor);
      for (int i : g[neighbor]) {
        if (visited.count(i) == 0) {
          dfs(i, currStep, maxStep, visited);
        }
      }
    }
  }

public:
  void setNvertex(int n) {
    this->nVertex = n;
  }

  void addEdge(int src, int dest) {
    g[src].push_back(dest);
  }

  void unReachable(int start, int steps) {
    set<int> visited;
    visited.insert(start);
    for (int neighbor : g[start]) {
      dfs(neighbor, 0, steps, visited);
    }

    int count = 0;
    for (int i = 1; i <= nVertex; i++) {
      if (visited.count(i) == 0) {
        count++;
      }
    }
    cout << count;
  }
};

int main() {

  int v;
  cin >> v;

  Graph g;
  g.setNvertex(v);
  int src, dest;
  while (true) {
    cin >> src >> dest;

    if (src && dest) {
      g.addEdge(src, dest);
    }
    else {
      break;
    }
  }

  int k, m;
  cin >> k >> m;
  g.unReachable(k, m);

  return 0;
}