// still wrong
#include <bits/stdc++.h>

using namespace std;

int tiger(int m, int n) {
    static map<pair<int, int>, int> mem;
    
    if(m == 0 && n == 0) return 1;

    if(mem.find(make_pair(m, n)) == mem.end()) {

        if(m == 0) {
            mem[make_pair(m, n)] =  tiger(m, n-1);
        }
        else if(n == 0) {
            mem[make_pair(m, n)] = tiger(m-1, n);
        }
        else {
            mem[make_pair(m, n)] = tiger(m-1, n) + tiger(m, n-1);
        }
        
        return mem[make_pair(m, n)];
    }
    else {
        return mem[make_pair(m, n)];
    }
}

int main() {

    cout << tiger(2,2);

    return 0;
}