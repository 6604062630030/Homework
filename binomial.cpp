// binomial top down
#include <bits/stdc++.h>

using namespace std;

int binomial(int n,  int k) {
    static map<pair<int,int>, int> mem;

    if(n == k || k == 0) return 1;

    if(mem.find(make_pair(n, k)) == mem.end()) {
        mem[make_pair(n, k)] = binomial(n - 1, k - 1) + binomial(n - 1, k);
        return mem[make_pair(n, k)];
    }
    else {
        return mem[make_pair(n, k)];
    }

}

int main() {

    cout << binomial(3,2);
    
    return 0;
}
