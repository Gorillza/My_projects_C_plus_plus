#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
// 0 - office
// 1 - home
// 2 - store

int main() {
    vector<int> s;
    vector<int> h;
    vector<int> hs;
    for (int i = 0; i < 10; i++) {
        int j = 0;
        cin >> j;
        if (j == 1) {
            h.push_back(i + 1);
            hs.push_back(j);
        }
        if (j == 2) {
            s.push_back(i + 1);
            hs.push_back(j);

        }
    }


    int r = 0;
    /*
    if (s.size() >= 2) {
        for (int i = 0; i < h.size(); i++) {
            auto ub = upper_bound(begin(s), end(s), h[i]);
            auto lb = lower_bound(begin(s), end(s), h[i]);
            lb--;
            if (r <= (min(*ub - h[i], h[i] - *lb))) {
                r = (min(*ub - h[i], h[i] - *lb));
            }

        }
    }
    else {
        r = abs(s[0] - h[0]);
        for (int i = 0; i < h.size(); i++) {
            if (r < abs(s[0] - h[i])) {
                r = abs(s[0] - h[i]);
             }

        }
    }
    */
    vector<int> a;
    r = 0;
    int k = 0;
    for (int i = 0; i < h.size(); i++) {
        r = 10;
        for (int j = 0; j < s.size(); j++) {
            if (r >= abs(s[j] - h[i])) {
                r = abs(s[j] - h[i]);
            }
        }
        a.push_back(r);
    }
    sort(a.begin(), a.end());

    cout << a[a.size()-1];
    return 0;
}