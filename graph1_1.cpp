// shortest path with bfs undirected
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Graph {
private:
  unordered_map<int, vector<int>> g;

  int calShort(unordered_map<int, int> parent, int src, int dest) {
    vector<int> path;
    for (auto it = parent.find(dest); it->second != -1; it = parent.find(it->second)) {
      path.push_back(it->first);
    }

    // print path
    // cout << src << " -> ";
    // for (int i = path.size() - 1; i >= 0; i--) {
    //   cout << path[i] << " -> ";
    // }
    // cout << endl;
    return path.size();
  }

public:
  void addEdge(int src, int dest) {
    g[src].push_back(dest);
  }

  void shortestPath(int src, int dest) { // inspired by bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
      int current = q.front();
      q.pop();
      for (int v : g[current]) {
        if (!visited[v]) {
          q.push(v);
          visited[v] = true;
          parent[v] = current;
        }
      }
    }

    cout << calShort(parent, src, dest);
  }
};

int main() {

  Graph g;

  int n;
  cin >> n;

  int vertex;

  for (int i = 0; i < n; i++) {
    cin >> vertex;
    int edge = -1;
    while (edge) {
      cin >> edge;
      if (edge != 0) {
        g.addEdge(vertex, edge);
      }
    }
  }

  int src, dest;
  cin >> src >> dest;

  g.shortestPath(src, dest);

  return 0;
}