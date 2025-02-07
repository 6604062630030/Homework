#include<bits/stdc++.h>


using namespace std;

int Count = 0;

void subset1(int *x, int k, int n) {
    
    if (n == k) {
        int flag = 0;

        for(int j=1; j<k; j++) {
            for(int p=0; p<j; p++) {
                if((abs(p-j) == abs(x[p] - x[j])) || (x[j] == x[p])) {
                    flag = 1;
                }
            }
        }

        Count++;
        if(flag == 0) {
            for(int i=0; i<k; i++) {
                cout << x[i] << " ";
            }
            cout << " ans " << endl;
        }
        else {
            for(int i=0; i<k; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        }
    }
    else {
        bool ispass = true;
        for(int i=0; i<n; i++) {
            for(int j=1; j<k; j++) {
                if(!ispass) {
                    break;
                }
                for(int p=0; p<j; p++) {
                    if(!ispass) {
                        break;
                    }
                    if((abs(p-j) == abs(x[p] - x[j])) || (x[j] == x[p])) {
                        ispass = false;
                    }
                }
            }

            if(!ispass) {
                continue;
            }

            x[k] = i;
            subset1(x, k + 1, n);
        }
    }
}

int main() {
    int n = 4;
    int x[n];

    subset1(x, 0, n);

    cout << Count;

    return 0;
}