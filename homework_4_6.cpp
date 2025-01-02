#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

void selection(int *arr, int n);
void selection_Vec(vector<int> &arr, int n);

int main() {

  int n;
  cin >> n;

  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  selection(arr, n);

  string str1;
  for (int i = 0; i < n; i++) {
    str1 += to_string(arr[i]);
  }
  cout << str1 << endl;

  // 2 // eror test case 2
  stack<char> s;
  unordered_map<char, int> dupe;
  for (int i = 0; i < str1.length(); i++) {
    if (s.empty() || s.top() == str1[i]) {
      s.push(str1[i]);
      cout << str1[i] << endl;
    }
    else {
      dupe[s.top()] = s.size();
      while (!s.empty()) { //clear stack
        s.pop();
      }
      s.push(str1[i]);
    }
  }
  // Handle the last element in the stack
  if (!s.empty()) {
    dupe[s.top()] = s.size();
  }

  int maxDupe = 0;
  for (auto pair : dupe) {
    if (pair.second > maxDupe) {
      maxDupe = pair.second;
    }
    cout << "pair " << pair.first << " : " << pair.second << endl;
  }

  vector<int> keep;
  for (auto pair : dupe) {
    if (pair.second == maxDupe) {
      keep.push_back(pair.first - '0');
    }
  }
  selection_Vec(keep, keep.size());

  for (int i = 0; i < keep.size(); i++) {
    cout << keep[i] << " ";
  }
  cout << endl;

  // 3
  char t = '-';
  for (int i = 0; i < str1.size(); i++) {
    if (str1[i] != t) {
      cout << str1[i];
      t = str1[i];
    }
  }

  return 0;
}

void selection(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
}

void selection_Vec(vector<int> &arr, int n) {

  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
}