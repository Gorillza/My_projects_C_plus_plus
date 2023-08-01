#include<iostream>
#include<vector>
#include<set>
#include<utility>

using namespace std;

int main() {
    long long M, N, first, second;
    cin >> M >> N;
    vector<pair<long long, long long>> vp;
    vector<long long> v;

    for (int i = 0; i < N; i++) {
        cin >> first >> second;
        auto p = make_pair(first, second);
        vp.push_back(p);
    }

    long long it = 0, sum = 0,index=0;

    for (int i = 0; i < vp.size(); i++) {
        for (int j = i+1; j < vp.size(); j++) {
            long long number = (vp[i].first - vp[j].second) * (vp[j].first - vp[i].second);
            if (i != j) {
                if ( number >= 0){
                    index++;
                    it++;
                    break;
                }
            }
        }
        if (it == 1) {
            it = 0;
            continue;
        }
        sum++;
    }
    cout << sum;


    return 0;
}