#include<iostream>
#include<vector>
#include<algorithm>
#include<map>



using namespace std;

int main() {
    long long N, M, k, sum = 0, index = 0, total = 0;
    cin >> N >> M;
    vector<vector<long long>> a;
    map<long long, vector<long long>> m;
    vector<long long> v;
    vector<long long> v1;
    bool t = false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> k;
            sum += k;
            v.push_back(k);
        }
        m[sum].push_back(i);
        sum = 0;
        a.push_back(v);
        v.clear();
    }
    index = m.begin()->second[0];

    for (int i = 0; i < M; i++) {
        if (t) {
            cout << " ";
        }
        cout << a.at(index).at(i);
        t = true;
    }




    return 0;
}