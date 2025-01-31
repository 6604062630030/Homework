#include<bits/stdc++.h>

using namespace std;

vector<int> idv;
vector<int> idw;
int maxV;

void print_sol(int *x, int *w, int *v, int maxw, int n) {
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", x[i]);
    // }
    // printf("\n");
    int sumV=0;
    int sumW=0;
    

    for (int i = 0; i < n; i++) {
        if(x[i] == 1) {
            sumV += v[i];
            sumW += w[i];
        }
    }

    if(sumW <= maxw && sumV > maxV) {
        idv.clear();
        idw.clear();
        for (int i = 0; i < n; i++) {
            if(x[i] == 1) {
                idv.push_back(v[i]);
                idw.push_back(w[i]);
            }
        }
        maxV = sumV;
    }

}

void subset1(int *x, int *w, int *v, int maxw, int l, int r) {
    if (l == r) {
        print_sol(x, w, v, maxw, r);
    } else {
        x[l] = 1;
        subset1(x, w, v, maxw, l + 1, r);
        x[l] = 0;
        subset1(x, w, v, maxw, l + 1, r);
    }
}

int main() {

    int n, maxWeight;
    cin >> n;
    int weight[n];
    int value[n];
    int x[n];

    for(int i=0; i<n; i++) {
        cin >> weight[i];
    }
    for(int i=0; i<n; i++) {
        cin >> value[i];
    }
    cout << "maxWeight: ";
    cin >> maxWeight;

    subset1(x, weight, value, maxWeight, 0, n);

    for(int i : idv) {
        cout << i << " ";
    }
    cout << endl;
    for(int i : idw) {
        cout << i << " ";
    }
    cout << endl;
    cout << maxV;

    return 0;
}