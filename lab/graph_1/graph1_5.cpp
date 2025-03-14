#include <bits/stdc++.h>

using namespace std;

char arr[100][100];

void floodFill(int x, int y, int w, int h, char target, int &count) {
  if (x < 0 || x > w || y < 0 || y > h || arr[y][x] != target) {
    return;
  }

  count++;
  arr[y][x] = 'G'; // Mark as visited

  // Recursively check neighbors
  floodFill(x - 1, y, w, h, target, count); // Up
  floodFill(x + 1, y, w, h, target, count); // Down
  floodFill(x, y - 1, w, h, target, count); // Left
  floodFill(x, y + 1, w, h, target, count); // Right
}

int main() {

  int height, width;
  cin >> height >> width;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> arr[i][j];
    }
  }

  int x, y;
  cin >> y >> x;

  int count = 0;

  floodFill(x - 1, y - 1, width - 1, height - 1, arr[y - 1][x - 1], count);
  cout << count;

  return 0;
}
