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

  int getData() {
    return this->data;
  }

  int getWeight() {
    return this->weight;
  }
};

class Graph { // ไม่รองรับ isolated vertex
private:
  map<int, vector<Node>> g;

public:
  void addEdge(int src, int dest, int weight) {
    g[src].emplace_back(dest, weight);
  }

  void addEdge(int src, int dest) {
    g[src].emplace_back(dest);
  }

  int unweightedShortestPath(int src, int dest) { // ver. bfs
    map<int, int> distance;
    distance[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (Node neighbor : g[curr]) {
        if (distance.find(neighbor.getData()) == distance.end()) {
          distance[neighbor.getData()] = distance[curr] + neighbor.getWeight();
          q.push(neighbor.getData());
          if (neighbor.getData() == dest) return distance[neighbor.getData()];
        }
      }
    }
    return 0;
  }

  int weightedShortestPath(int src, int dest) { // ver. dijkstra: works for all 4
    map<int, int> distance;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Set all distances to infinity except the source
    for (auto pair : g) {
      distance[pair.first] = INT_MAX;
    }
    distance[src] = 0;
    pq.push({ 0, src });

    while (!pq.empty()) {
      int curr = pq.top().second;
      int dist = pq.top().first;
      pq.pop();

      // If we reached the destination, return the current distance
      if (curr == dest) return dist;

      // Process all neighbors of the current node
      for (Node neighbor : g[curr]) {
        int newDist = dist + neighbor.getWeight();
        if (newDist < distance[neighbor.getData()]) {
          distance[neighbor.getData()] = newDist;
          pq.push({ newDist, neighbor.getData() });
        }
      }
    }
    return -1; // if destination is unreachable
  }

};

int main() {

  cout << "hello graph";

  return 0;
}