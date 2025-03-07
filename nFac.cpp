// nFac top down
#include <bits/stdc++.h>

using namespace std;

unsigned long long int nFac(unsigned long long int num) {
   static map<unsigned long long int , unsigned long long int > mem;
   if(num < 2) return 1;

   if(mem.find(num) == mem.end()) {
    mem[num] =  num * nFac(num-1);
    return mem[num];
   }
   else {
    return mem[num];
   }
}

int main() {
    cout << nFac(20);
}