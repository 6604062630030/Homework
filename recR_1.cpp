#include <bits/stdc++.h>

using namespace std;

int recR_1(int n, int k) {
    static map<pair<int, int>, int> mem;
    
    if(k == 0 || k == 1 || n == k) return 1;

    if(mem.find(make_pair(n, k)) == mem.end()) {
        mem[make_pair(n, k)] = recR_1(n-1,k) + recR_1(n-1, k-2);
        return mem[make_pair(n, k)];
    }
    else {
        return mem[make_pair(n, k)];
    }
}

int main() {

    cout << recR_1(6,4);

    return 0;
}