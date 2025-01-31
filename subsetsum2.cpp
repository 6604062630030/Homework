#include <iostream>
#include <vector>

using namespace std;

void print_sol(int x[], int num[], int k, int n) {

    // for (int i = 1; i <= n; i++) {
    //     printf("%d ", x[i]);
    // }

    // printf("\n");

    int sum=0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        sum += num[x[i]];
        ans.push_back(num[x[i]]);
    }

    if(sum == k) {
        cout << "{ ";
        for(int i : ans) {
            cout << i << " ";
        }
        cout << " }" << endl;
    }
}

void subset2(int x[], int num[], int k, int l, int n) {

    print_sol(x, num, k, l);

    int j;
    if (l == 0) {
	    j = 1; 
    }
    else {
        j = x[l] + 1;
    }

    for (int i = j; i <= n; i++) {
        x[l + 1] = i;
        subset2(x, num, k, l + 1, n);
    }
}

int main() {
    int n = 3; 	// Number of elements
    cin >> n;
    int x[n + 1];	 // Array to store subset

    int num[n+1];
    for(int i=1; i<=n; i++) {
        cin >> num[i];
    }
    int k;
    cin >> k;

   subset2(x, num, k, 0, n);

    return 0;
}