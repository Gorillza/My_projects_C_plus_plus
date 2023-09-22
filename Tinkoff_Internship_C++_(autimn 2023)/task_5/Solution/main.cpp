#include<iostream>
#include<vector>
#include<set>
#include<utility>
using namespace std;

vector<int>comp;

void dfs(vector<vector<pair<long long,long long>>>& bv, vector<bool>& vb, long long now,long long path) {
    vb[now] = true;
    comp.push_back(now);
    for (auto i = 0; i < bv[now].size(); i++) {
        if (!vb[bv[now][i].first] && bv[now][i].second>path) {
            dfs(bv, vb, bv[now][i].first,path);
        }
    }
}

int main() {
    long long N = 0, M = 0, first = 0, second = 0, path = 0;
    cin >> N >> M;
    vector<vector<pair<long long,long long>>> bv(N + 1);

    vector<bool> vb(N + 1, false); // vershini
    set<long long>p;

    //Заполнение компонент связности
    for (auto i = 0; i < M; i++) {
        cin >> first >> second>>path;
        p.insert(path);
        bv.at(first).push_back({ second,path });
        bv.at(second).push_back({ first,path });
    }

    //Нахождение изначального количества штатов(компонент связности графа)
    int kol = 0;
    for (int i = 1; i <= N; ++i) {
        if (!vb[i]) {
            comp.clear();
            dfs(bv, vb, i,0);
            kol++;
        }
    }

    int now_kol = 0;
    while (true) {
        path = *p.begin();
        p.erase(p.begin());
        vb.assign(N + 1, false);

        //Поиск компонент связности при условии уничтожения дарог длиной <= path
        for (int i = 1; i <= N; ++i) {
            if (!vb[i]) {
                comp.clear();
                dfs(bv, vb, i, path);
                now_kol++;
            }
        }

        // Если число штатов изменилось значит уничтожение всех дорог <= path приводит к такоему значит
        // если отнять одну единицу то теперь будут уничтожены все дороги которые не создают новых штатов
        if (now_kol != kol) {
            cout<< --path;
            return 0;
        }
        now_kol = 0;
    }

    return 0;
}