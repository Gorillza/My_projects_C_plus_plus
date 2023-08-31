#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N = 0;
    cin >> N;
    vector<int> d(N+1,2e9);
    vector<int> noms(N + 1);
    d[1] = 0;
    for (int i = 2; i <= N; i++) {
        
        if (i % 2 == 0 && d[i] > d[(i / 2)] + 1) {
            d[i] = d[(i / 2)] + 1;
            noms[i] = i / 2;
        }    
        if (i%3 == 0 && d[i] > d[(i / 3)] + 1) {
            d[i] = d[(i / 3)] + 1;
            noms[i] = i / 3;
        }
        if (d[i] > d[(i - 1)] + 1) {
            d[i] = d[(i - 1)] + 1;
            noms[i] = i - 1;
        }
    }

    cout << d[N] << endl;
    int x = N;
    vector<int> path;
    path.push_back(N);
    while (noms[x] != 0) {
        path.push_back(noms[x]);
        x = noms[x];
    }
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i]<<" ";
    }
    return 0;
}