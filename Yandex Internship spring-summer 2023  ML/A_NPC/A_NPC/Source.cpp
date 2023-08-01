#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main() {
    long long N, npc, indikator = 0;
    vector<long long> v;
    vector<long long> a;
    set<long long> g_index;
    set<long long> b_index;
    set<long long> s;
    set<long long> sub;
    cin >> N;
    v.push_back(0);
    for (size_t i = 0; i < N; i++) {
        cin >> npc;
        v.push_back(npc);
        if (npc == -1) {
            indikator++;
        }
    }

    if (indikator == 0) {
        cout << "NO";
        return 0;
    }

    long long head = 0, tail = 0, value = 0;

    for (size_t i = 1; i < v.size(); i++) {

        if (g_index.count(i)) {
            continue;
        }
        //head -это переменная которая содержит в себбе index нпс к которому мы должны пойти
        head = v[i];
        if (head < 0) {
            g_index.insert(i);//массив с хорошими индексами
            continue;
        }
        b_index.insert(i);
        //если число указывает на самого себя
        if (b_index.count(head)) {
            cout << "NO";
            return 0;
        }
        b_index.insert(head);
        

        while (true) {
            tail = v[head];
            if (tail < 0) {
                g_index.insert(head);//массив с хорошими индексами
                break;
            }
            if (b_index.count(tail)) {
                cout << "NO";
                return 0;
            }
            b_index.insert(tail);
            head = tail;
        }
        for (auto x : b_index) {
            g_index.insert(x);
        }
        b_index.clear();
    }


    cout << "Yes";
    return 0;
}