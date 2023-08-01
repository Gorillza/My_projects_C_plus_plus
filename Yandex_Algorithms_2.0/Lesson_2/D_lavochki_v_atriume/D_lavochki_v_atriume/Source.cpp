#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int l = 0;
    int k = 0;
    vector<int> v;
    cin >> l >>k;
    int j = 0;
    for (int i =0 ; i < k; i++) {
        cin >> j;
        v.push_back(j);
    }

    if (l % 2 == 1) {
        if (binary_search(v.begin(), v.end(), (l / 2))) {
            auto mid = lower_bound(v.begin(), v.end(), (l / 2));
            cout << *mid;
            return 0;
        }
    }
    auto second = lower_bound(v.begin(), v.end(), l / 2);
    auto first = --lower_bound(v.begin(), v.end(), l / 2);

    cout << *first <<" " << *second;
    
    return 0;
}