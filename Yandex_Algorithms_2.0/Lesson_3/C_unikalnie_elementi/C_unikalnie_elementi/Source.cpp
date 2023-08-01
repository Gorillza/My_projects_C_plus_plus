#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {
    map<int, int> a;
    vector<int>v;
    int k = 0;
    while (cin >> k) {
        a[k]++;
        v.push_back(k);
    }

    for (int i = 0; i < v.size(); i++) {
        if (a[v[i]] == 1) {
            cout << v[i]<<" ";
        }
    }

    return 0;
}