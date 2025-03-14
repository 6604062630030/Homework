#include <iostream>
#include <vector>
#include <stack>
#include<map>

using namespace std;


void selection(vector<int> &arr, int n);
int find(vector<char> &str, char target);
int ToInt(char c);

int main() {

  int n, temp;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    arr.push_back(temp);
  }
  selection(arr, n);

  // 1
  string str;
  for (int i = 0; i < n; i++) {
    str += to_string(arr[i]);
  }
  cout << str << endl;

  // 2
  map<int, int> mp;
  stack<char> stk;
  for (int i = 0; i < str.size(); i++) { //count max 
    if (stk.empty()) {
      stk.push(str[i]);
      if (mp.find(str[i]) == mp.end()) {
        mp[ToInt(str[i])] = 1;
        //cout << "add" << ToInt(str[i]) << endl;
      }
    }
    else if (str[i] == stk.top()) {
      stk.push(str[i]);
      if (mp[ToInt(str[i])] < stk.size()) {
        mp[ToInt(str[i])] = stk.size();
        //cout << "update" << ToInt(str[i]) << " " << stk.size() << endl;
      }
    }
    else {
      while (!stk.empty()) {
        stk.pop();
      }
      stk.push(str[i]);
      if (mp.find(ToInt(str[i])) == mp.end()) {
        mp[ToInt(str[i])] = 1;
        //cout << "added" << ToInt(str[i]) << endl;
      }
    }
  }

  int max = 0;
  for (auto pair : mp) {
    if (pair.second > max) {
      max = pair.second;
    }
  }

  vector<int> ans;
  for (auto pair : mp) {
    if (pair.second == max) {
      ans.push_back(pair.first);
      //cout << "debug: " << pair.first << endl;
    }
  }
  selection(ans, ans.size());

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  // 3
  char t = '-';
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != t) {
      cout << str[i];
      t = str[i];
    }
  }

  return 0;
}

void selection(vector<int> &arr, int n) {

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

int find(vector<char> &str, char target) {
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == target) {
      return i;
    }
  }
  return -1;
}

int ToInt(char c) {
  return c - '0';
}