// find can't access vertex in each vertex
#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
  map<int, vector<int>> g;
  vector<int> allVertex;
public:
  void setAllVertex(vector<int> Vertex) {
    this->allVertex = Vertex;
  }

  void addEdge(int src, int dest) {
    g[src].push_back(dest);
  }

  void cantAccess() {

    for (auto pair : g) {
      bool allfound = true;

      for (int j : allVertex) {
        bool isfound = false;

        for (int i : pair.second) {
          if (i == j) {
            isfound = true;
            break;
          }
        }

        if (!isfound && !(j == pair.first)) {
          allfound = false;
          cout << j << " ";
        }
      }

      if (allfound) {
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