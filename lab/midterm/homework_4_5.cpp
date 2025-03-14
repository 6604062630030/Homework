#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

    int n, temp;
    unordered_map<int, int> m1, m2, all;
    vector<int> m1Order, m2Order, allOrder;
    cin >> n;

    int arr1[n];
    int arr2[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        if (m1.find(arr1[i]) == m1.end()) {
            m1Order.push_back(arr1[i]);
        }
        if (all.find(arr1[i]) == all.end()) {
            allOrder.push_back(arr1[i]);
        }
        m1[arr1[i]]++;
        all[arr1[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
        if (m2.find(arr2[i]) == m2.end()) {
            m2Order.push_back(arr2[i]);
        }
        if (all.find(arr2[i]) == all.end()) {
            allOrder.push_back(arr2[i]);
        }
        m2[arr2[i]]++;
        all[arr2[i]]++;
    }

    // copy to vector
    vector<int> Intersect, Union;
    for (int i : m1Order) {
        if (m2.find(i) != m2.end()) {
            Intersect.push_back(i);
        }
    }
    for (int i : allOrder) {
        Union.push_back(i);
    }

    // print
    for (int i = 0; i < Intersect.size(); i++) {
        cout << Intersect[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < Union.size(); i++) {
        cout << Union[i] << " ";
    }

    return 0;
}