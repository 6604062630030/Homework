#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
  unordered_map<int, vector<int>> g;

  void recwalk(set<int> &mem, int curr, int count, int steps) {
    if (count == steps) return;
    mem.insert(curr);
    for (int i : g[curr]) {
      recwalk(mem, i, count + 1, steps);
    }
  }

public:
  void addEdge(int src, int dest) {
    g[src].push_back(dest);
  }

  int unReachableVertex(int start, int steps) {
    set<int> mem;
    int count = 1;
    mem.insert(start);
    for (int i : g[start]) {
      recwalk(mem, i, count, steps);
    }
    count = 0; // reuse count for counting unvisit
    for (auto pair : g) {
      if (!mem.count(pair.first)) {
        count++;
      }
    }
    return count;
  }

  void print() {
    for (auto pair : g) { //use auto p instead of std::pair<std::string, std::vector<Node>> p
      cout << pair.first << "-> ";

      for (int node : pair.second) {
        cout << node << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  int n;
  Graph g;
  cin >> n;

  int v = -1, e = -1;
  while (true) {
    cin >> v;
    cin >> e;
    if (v == 0 && e == 0) break;
    g.addEdge(v, e);
  }

  int start, m;
  cin >> start >> m;

  g.print();

  cout << g.unReachableVertex(start, m);

  return 0;
}