#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<long long> get(long long& x, unordered_map<long long,vector<long long>>& band, vector<long long>& p) {
    return band[p[x]];
}

void uni(long long x, long long y,vector<long long>& p, unordered_map<long long, vector<long long>>& band , unordered_map<long long, long long>& count_band){
    
    //Если попытались обьядинить тех кто уже обьяденен
    if (p[x] == p[y]) {
        return;
    }

    vector<long long> xx;
    vector<long long> yy;

    xx = get(x, band,p);
    yy = get(y, band,p);

    //переделал команды 
    if (xx.size() > yy.size()) {
        long long n = p[y];
        for (auto& i : yy) {
            p[i] = p[x];
            band[p[x]].push_back(i);
        }
        band[n].clear();

        //увеличиваю колинчство банд в которых побывали участники
        for (auto& i : band[p[x]]) {
            count_band[i]++;
        }
    }
    else
    {
        long long n = p[x];
        for (auto& i : xx) {
            p[i] = p[y];
            band[p[y]].push_back(i);
        }
        band[n].clear();

        //увеличиваю колинчство банд в которых побывали участники
        for (auto& i : band[p[y]]) {
            count_band[i]++;
        }
    }
    return;
}


int main() {
    long long N = 0, M = 0;
    cin >> N >> M;
    vector<long long> p(N+1,0);
    unordered_map<long long, long long> count_band;
    unordered_map<long long, vector<long long>> band;
    for (int i = 1; i <= N; i++) {
        p[i] = i;
        count_band[i] = 1;
        band[i].push_back({ i });
    }

    int op = 0;
    long long x = 0, y = 0;
    for (int i = 0; i < M; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            uni(x, y, p, band, count_band);
        }
        if (op == 2) {
            cin >> x >> y;
            if (p[x] == p[y]) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
        if (op == 3) {
            cin >> x;
            cout << count_band[x] << "\n";
        }
    }
    return 0;
}