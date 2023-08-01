#include<iostream>
#include<vector>
#include<algorithm>

#include<set>
using namespace std;

int main() {
    vector<long long> v;
    vector<long long> v1;

    int N = 0;
    long long k = 0;
    cin >> N;
    for (size_t i = 0; i < N; i++) {
        cin >> k;
        v.push_back(k);
        v1.push_back(k);
    }
    sort(v1.begin(), v1.end());
    bool f = false;
    for (auto& x : v) {
        if (f) {
            cout << " ";
        }
        if (x == v1[0]) {
            x = v1[v1.size() - 1];
        }
        cout << x;
        f = true;
    }

    return 0;
}