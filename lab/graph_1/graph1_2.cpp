// find can't access vertex in each vertex
#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
  map<int, vector<int>> g;
  vector<int> allVertex;

  void dfs(int src, set<int> &visited) {
    visited.insert(src);

    for (int i : g[src]) {
      if (!visited.count(i)) {
        dfs(i, visited);
      }
    }
  }

public:
  void setAllVertex(vector<int> Vertex) {
    this->allVertex = Vertex;
  }

  void addEdge(int src, int dest) {
    g[src].push_back(dest);
  }

  void cantAccess() {
    for (auto vertex : allVertex) {
      set<int> visited;
      bool allVisit = true;
      dfs(vertex, visited);

      // check if all visit
      for (int i : allVertex) {
        if (!visited.count(i)) {
          allVisit = false;
          cout << i << " ";
        }
      }

      if (allVisit) {
        cout << 0;
      }
      cout << endl;
    }
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

  vector<int> Vertex;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    Vertex.push_back(temp);
  }

  g.setAllVertex(Vertex);
  g.cantAccess();

  return 0;
}