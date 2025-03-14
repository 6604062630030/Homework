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
};

class Graph {
public:
  map<int, vector<Node>> g;
  set<int> verticies;

  void addEdge(int src, int dest, int weight) {
    g[src].emplace_back(dest, weight);
    verticies.insert(src);
    verticies.insert(dest);
  }

  int prim(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    set<int> inMst;
    map<int, int> minEdge;

    for (int vertex : verticies) {
      minEdge[vertex] = INT_MAX;
    }
    minEdge[start] = 0;
    pq.push({ 0, start });

    int totalWeight = 0;

    while (!pq.empty()) {
      int weight = pq.top().first;
      int curr = pq.top().second;
      pq.pop();

      if (inMst.count(curr)) continue; // Skip already included nodes

      inMst.insert(curr);
      totalWeight += weight;

      for (Node neighbor : g[curr]) {
        if (!inMst.count(neighbor.data) && neighbor.weight < minEdge[neighbor.data]) {
          minEdge[neighbor.data] = neighbor.weight;
          pq.push({ neighbor.weight, neighbor.data });
        }
      }
    }
    return totalWeight;
  }

  int prim(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    map<int, int> minEdge;
    set<int> inMst;

    for (int vertex : verticies) {
      minEdge[vertex] = INT_MAX;
    }
    inMst.insert(start);
    pq.push({ 0, start });

    int totalWeight = 0;

    while (!pq.empty()) {
      int weight = pq.top().first;
      int curr = pq.top().second;
      pq.pop();

      if (inMst.count(curr)) continue;

      inMst.insert(curr);
      totalWeight += weight;

      for (Node neighbor : g[curr]) {
        if (neighbor.weight < minEdge[neighbor.data] && !inMst.count(neighbor.data)) {
          minEdge[neighbor.data] = neighbor.weight;
          pq.push({ neighbor.weight, neighbor.data });
        }
      }
    }
    return totalWeight;
  }

  int prim(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    map<int, int> minEdge;
    set<int> inMst;

    for (int vertex : verticies) {
      minEdge[vertex] = INT_MAX;
    }
    minEdge[start] = 0;
    pq.emplace(0, start);

    int totalWeight = 0;

    while (!pq.empty()) {
      int weight = pq.top().first;
      int curr = pq.top().second;
      pq.pop();

      if (inMst.count(curr)) continue;
      inMst.insert(curr);
      totalWeight += weight;

      for (Node neighbor : g[curr]) {
        if ((neighbor.weight < minEdge[neighbor.data]) && !inMst.count(neighbor.data)) {
          minEdge[neighbor.data] = neighbor.weight;
          pq.emplace(neighbor.weight, neighbor.data);
        }
      }
    }
    return totalWeight;
  }

  int prim(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    set<int> inMst;
    map<int, int> minEdge;

    for (int vertex : verticies) {
      minEdge[vertex] = INT_MAX;
    }
    minEdge[start] = 0;
    pq.emplace(0, start);

    int totalWeight = 0;

    while (!pq.empty()) {
      int weight = pq.top().first;
      int curr = pq.top().second;
      pq.pop();

      if (inMst.count(curr)) continue;
      inMst.insert(curr);
      totalWeight += weight;

      for (Node neighbor : g[curr]) {
        if (neighbor.weight < minEdge[neighbor.data] && !inMst.count(neighbor.data)) {
          pq.emplace(neighbor.weight, neighbor.data);
          minEdge[neighbor.data] = neighbor.weight;
        }
      }
    }
    return totalWeight;
  }

  int prim(int start) {
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    map<int, int> minEdge;
    set<int> inMst;

    for (int vertex : verticies) {
      minEdge[vertex] = INT_MAX;
    }
    minEdge[start] = 0;
    pq.emplace(0, start);

    int totalWeight = 0;

    while (!pq.empty()) {
      int weight = pq.top().first;
      int curr = pq.top().second;
      pq.pop();

      if (inMst.count(curr)) continue;
      inMst.insert(curr);
      totalWeight += weight;

      for (Node neighbor : g[curr]) {
        if (neighbor.weight < minEdge[neighbor.data] && !inMst.count(neighbor.data)) {
          minEdge[neighbor.data] = neighbor.weight;
          pq.emplace(neighbor.weight, neighbor.data);
        }
      }
    }
    return totalWeight;
  }
};

int main() {


  return 0;
}