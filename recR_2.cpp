#include <bits/stdc++.h>

using namespace std;

int recR_2(int n) {
    static map<int, int> mem;
    
    if(n == 0) return 0;
    if(n < 3) return 1;

    if(mem.find(n) == mem.end()) {
        mem[n] = recR_2(n-1) + recR_2(n-2) - recR_2(n-3);
        return mem[n];
    }
    else {
        return mem[n];
    }
}

int main() {

    cout << recR_2(7);

    return 0;
}