#include<bits/stdc++.h>

using namespace std;

int Count = 0;

void print_sol(int x[], int num[], int n) {
    for (int i = 0; i < n; i++) {
        if(x[i] == 1) {
            cout << num[i] << " ";
        }
    }
    cout << endl;
}

void subset1(int x[], int num[], int k, int l, int r, int sum) {

    if(sum == k) {
        print_sol(x, num, r);
        return;
    }

    if(l == r) { // reach the last num but still less than k
        return;
    } 

    if(sum > k) { // if sum is greater than k, it will return back to find another route
        return ;
    }

    Count++;

    x[l] = 1;
    sum += num[l];
    subset1(x, num, k, l + 1, r, sum);

    x[l] = 0;
    sum -= num[l];
    subset1(x, num, k, l + 1, r, sum);
    
}

int main() {
    int n = 4;            // Number of elements
    // cin >> n;
    int x[n];         // Array to store subset
    int num[] = {25, 10, 9, 2};
    // for(int i=0; i<n; i++) {
    //     cin >> num[i];
    // }
    int k = 36;
    // cin >> k;

    subset1(x, num, k, 0, n, 0);

    cout << Count;

    return 0;
}