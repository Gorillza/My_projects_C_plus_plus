#include<iostream>
#include<set>
using namespace std;

int main() {
    long long N = 0, s = 0;
    cin >> N >> s;
    set<long long> r;
    int k = 0;
    for (long long i = 0; i < N; i++) {
        cin >> k;
        r.insert(k);
    }

    auto it = r.lower_bound(s);

    if (it == r.end()) {
        cout << *prev(it);
        return 0;
    }
    if (*it > s) {
        if (it == r.begin()) {
            cout << 0;
            return 0;
        }
        else {
            cout << *prev(it);
            return 0;
        }
    }
    if (*it == s) {
        cout << *it;
    }
    return 0;
}