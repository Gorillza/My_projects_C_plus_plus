#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;


void dfs (vector<vector<long long>>& bv, vector<bool>& vb ,long long now){
    vb[now] = true;
    for (auto i = 0; i <bv[now].size(); i++) {
        if (!vb[bv[now][i]]) {
            dfs(bv, vb, bv[now][i]);
        }
    }
}


int main() {
    long long N = 0, M = 0, first = 0, second = 0;
    cin >> N >> M;
    vector<vector<long long>> bv(N + 1);


    vector<bool> vb(N+1, false); // vershini
    vector<long long> f;

    for (auto i = 0; i < M; i++) {
        cin >> first >> second;
        bv.at(first).push_back(second);
        bv.at(second).push_back(first);
    }
    /*
    int i = 0;
    for (auto& x : bv){
        cout << i << ":";
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << endl;
        i++;
    }
    */
    dfs(bv, vb, 1);
    
    for (int i = 0; i < vb.size(); i++) {
        if (vb[i]) {
            f.push_back(i);
        }
    }

    cout << f.size() << endl;
    bool t = false;
    for (auto x : f) {
        if (t) {
            cout << " ";
        }
        cout << x;
        t = true;
    }

    return 0;
}