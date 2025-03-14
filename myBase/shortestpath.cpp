#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int data;
  int weight;

  Node(int data, int weight) {
    this->data = data;
    this->weight = weight;
  }

  Node(int data) {
    this->data = data;
    this->weight = 1;
  }
};

class Graph {
private:
  map<int, vector<Node> > g;
  set<int> vertices; // Stores all unique vertices

public:
  void addEdge(int src, int dest, int weight) {
    g[src].emplace_back(dest, weight);
    vertices.insert(src);
    vertices.insert(dest);
  }

  void addEdge(int src, int dest) {
    g[src].emplace_back(dest);
    vertices.insert(src);
    vertices.insert(dest);
  }

  int shortestPath(int src, int dest) { // works for all
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    map<int, int> distance;

    for (int vertex : vertices) {
      distance[vertex] = INT_MAX;
    }
    distance[src] = 0;
    pq.push({ 0, src });

    while (!pq.empty()) {
      int dist = pq.top().first;
      int curr = pq.top().second;
      pq.pop();

      if (curr == dest) return dist;

      for (Node neighbor : g[curr]) {
        int newDistance = neighbor.weight + dist;

        if (newDistance < distance[neighbor.data]) {
          distance[neighbor.data] = newDistance;
          pq.push({ newDistance, neighbor.data });
        }
      }
    }
    return -1;
  }
};

int main() {

  int edge;
  cin >> edge;

  int src, dest, weight;
  Graph g;
  for (int i = 0; i < edge; i++) {
    cout << "src dest weight: ";
    cin >> src >> dest;
    g.addEdge(src, dest);
    // g.addEdge(dest, src);
  }

  while (true) {
    cout << "input src and dest:";
    cin >> src >> dest;
    if (!(src || dest)) break;
    cout << "shortest path from " << src << " to " << dest << " = " << g.shortestPath(src, dest) << endl;
  }

  return 0;
}
