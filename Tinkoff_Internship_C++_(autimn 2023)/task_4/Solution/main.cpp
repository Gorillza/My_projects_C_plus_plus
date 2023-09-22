#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool comp(const long long& e1, const long long& e2) {
    return e1 > e2;
}

int main() {

    int N = 0, M = 0, ai = 0;
    cin >> N >> M;
    vector<long long>d;
    unordered_map<long long, long long> m;
    vector<pair<long long, long long>> v;
    for (int i = 0; i < M; i++) {
        cin >> ai;
        d.push_back(ai);
        d.push_back(ai);
    }

    sort(d.begin(), d.end(),comp);
    bool flag = false;
    m[0] = 0;
    for (int i = 0; i < d.size(); i++) {
        for (auto j : m) {
            v.push_back({j.first+d[i],d[i]});
        }
        for (auto j : v) {
            if (m.count(j.first) == 0) {
                m[j.first] = j.second;
            }
        }
        v.clear();

        if (m.count(N) == 1) {
            flag = true;
            break;
        }
    }

    int k = 0;
    long long x = N;
    vector<long long> path;
    if (flag) {
        while (x != 0) {
            k++;
            path.push_back(m[x]);
            x -= m[x];
        }
    }
    else {
        cout << -1;
        return 0;
    }

    cout << k << endl;
    for (auto i : path) {
        cout << i << " ";
    }

    return 0;
}