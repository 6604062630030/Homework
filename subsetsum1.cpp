#include<bits/stdc++.h>

using namespace std;

void print_sol(int x[], int num[], int k, int n) {
    // for (int i = 0; i < n; i++) {
    //     cout << x[i] << " ";
    // }
    // cout << endl;

    vector<int> ans;
    int sum=0;
    for(int i=0; i<n; i++) {
        if(x[i] == 1) {
            sum += num[i];
            ans.push_back(num[i]);
        }
    }

    if(sum == k) {
        cout << "{";
        for(int i : ans) {
            cout << i << " ";
        }
        cout << "}" << endl;
    }
    
}

void subset1(int x[], int num[], int k, int l, int r) {
    if (l == r) {
        print_sol(x, num, k, r);
    } else {
        x[l] = 0;
        subset1(x, num, k, l + 1, r);
        x[l] = 1;
        subset1(x, num, k, l + 1, r);
    }
}

int main() {
    int n;            // Number of elements
    cin >> n;
    int x[n];         // Array to store subset
    int num[n];
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    int k;
    cin >> k;

    subset1(x, num, k, 0, n);

    return 0;
}