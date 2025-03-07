// still wrong
#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
  unordered_map<int, set<int>> g;
  unordered_map<int, int> sumPath; // collect sum of path each vector

  int shortestPath(int src, int dest) { // inspired by bfs
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

    return calShort(parent, src, dest);
  }

  int calShort(unordered_map<int, int> parent, int src, int dest) {
    if (src == dest) return 0; // If src and dest are the same, return 0

    if (parent.find(dest) == parent.end()) {
      return INT_MAX; // Return a large value if there's no path
    }

    vector<int> path;
    for (auto it = parent.find(dest); it->second != -1; it = parent.find(it->second)) {
      path.push_back(it->first);
    }

    return path.size();
  }

  void calDistance(int vertex, set<int> edge) {
    //initial
    set<int> neighbor = edge;
    neighbor.insert(vertex);
    for (auto pair : g) {
      if (!neighbor.count(pair.first)) {
        sumPath[vertex] = neighbor.size() + shortestPath(vertex, pair.first) - 1;
      }
    }
  }

public:
  void addEdge(int src, int dest) {
    g[src].insert(dest);
  }

  int shortestToAll() {
    for (auto pair : g) {
      calDistance(pair.first, pair.second);
    }

    // find min in sumPath
    int pinVeretex;
    int min = 9999999;
    for (auto pair : sumPath) {
      if (pair.second < min) {
        min = pair.second;
        pinVeretex = pair.first;
      }
    }

    return pinVeretex;
  }

};

int main() {

  int v, e;
  cin >> v >> e;
  Graph g;

  int t1, t2;
  for (int i = 0; i < e; i++) {
    cin >> t1 >> t2;
    g.addEdge(t1, t2);
  }

  cout << g.shortestToAll();   

  return 0;
}
