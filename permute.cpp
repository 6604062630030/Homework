#include <iostream>
#include <algorithm>

using namespace std;

void permute(int *arr, int start, int end) {
  if (start == end) {
    for (int i = 0; i < end; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = start; i < end; i++) {
    swap(arr[start], arr[i]);
    permute(arr, start + 1, end);
    swap(arr[start], arr[i]);
  }
}

// real

void print(int n, char ar[]) {
  for (int i = 0; i < n; i++) {
    cout << ar[i];
  }
  cout << "\n";
}

void RightRotate(char arr[], int i, int j) {
  char temp = arr[j];
  for (int k = j; k > i; k--) {
    arr[k] = arr[k - 1];
  }
  arr[i] = temp;
}

void LeftRotate(char arr[], int i, int j) {
  char temp = arr[i];
  for (int k = i; k < j; k++) {
    arr[k] = arr[k + 1];
  }
  arr[j] = temp;
}

void generate(char arr[], int i, int n) {
  if (i == n - 1) {
    print(n, arr);
    return;
  }
  generate(arr, i + 1, n);
  for (int j = i + 1; j < n; j++) {
    RightRotate(arr, i, j);
    generate(arr, i + 1, n);
    LeftRotate(arr, i, j);
  }
}

// real

void rr(int *arr, int i, int j) {
  int temp = arr[j];
  for (int k = j; k > i;k--) {
    arr[k] = arr[k - 1];
  }
  arr[i] = temp;
}

void lr(int *arr, int i, int j) {
  int temp = arr[i];
  for (int k = i; k < j;k++) {
    arr[k] = arr[k + 1];
  }
  arr[j] = temp;
}

void lexigo(int *arr, int l, int r) {
  if (l == r) {
    // print(arr, r);
    return;
  }
  lexigo(arr, l + 1, r);
  for (int i = l + 1; i < r;i++) {
    rr(arr, l, i);
    lexigo(arr, l + 1, r);
    lr(arr, l, i);
  }

}

int main() {
  int n = 4;
  int arr[] = { 1, 2, 3 ,4 };

  permute(arr, 0, n);

  return 0;
}
