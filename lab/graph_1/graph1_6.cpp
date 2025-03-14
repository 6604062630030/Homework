#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
  unordered_map<int, vector<int>> g;
  int nVertex;

  int shortestPath(int src, int dest) { // shortest path ver. undirected/directed unweight BFS
    map<int, int> distance;
    distance[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (int neighbor : g[curr]) {
        if (distance.find(neighbor) == distance.end()) {
          distance[neighbor] = distance[curr] + 1;
          q.push(neighbor);
          if (neighbor == dest) return distance[neighbor];
        }
      }
    }
    return 0;
  }

public:
  Graph(int n) {
    this->nVertex = n;
  }

  void addEdge(int src, int dest) {
    g[src].push_back(dest);
  }

  int ambulance() {
    set<int> totalDistance;
    int min = INT_MAX;
    int pin;
    for (int i = 1; i <= nVertex; i++) {
      int count = 0;
      for (int j = 1; j <= nVertex; j++) {
        count += shortestPath(i, j);
        // cout << i << " to " << j << " = " << shortestPath(i, j) << endl;
      }
      if (count < min) {
        min = count;
        pin = i;
      }
      // cout << "total dist for vertex " << i << " = " << count << endl;
    }
    return pin;
  }
};

int main() {

  int v, e;
  cin >> v >> e;

  Graph g(v);
  int tempa, tempb;
  for (int i = 0; i < e; i++) {
    cin >> tempa >> tempb;
    g.addEdge(tempa, tempb);
    g.addEdge(tempb, tempa);
  }

  cout << g.ambulance();

  return 0;
}
