#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

int main() {
    long long N = 0;
    long long x = 0;
    cin >> N;
    set<long long> s;
    vector<long long> v;
    long long set_size = s.size();
    map<long long, long long> a;
    for (int i = 0; i < N; i++) {
        cin >> x;
        s.insert(x);
        if (s.size() > set_size) {
            set_size += 1;
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());

    long long k = 0;
    cin >> k;
    long long z = 0;
    bool ff = false;
    for (int i = 0; i < k; i++) {
        if (ff) {
            cout << endl;
        }
        cin >> z;
        if (z<v[0]) {
            cout << 0;
            ff = true;
            continue;
        }
        if (z > v[v.size() - 1]) {
            cout << (v.size());
            ff = true;
            continue;
        }
        if (a[z] == 0) {
            auto it = lower_bound(v.begin(), v.end(), z);
            //auto iter = --it;
            cout << it - v.begin();
            a[z] = it - v.begin();
        }
        else {
            cout << a[z];
        }
        ff = true;
    }
    return 0;
}