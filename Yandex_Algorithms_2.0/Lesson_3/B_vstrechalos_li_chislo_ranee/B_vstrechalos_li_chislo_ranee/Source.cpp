#include<iostream>
#include<map>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    map<int, int> a;
    vector<int> v;
    int N = 0;
    while (cin >> N && cin) {
        v.push_back(N);
    }

    for (size_t i = 0; i < v.size(); i++) {
        if (a[v[i]] == 0) {
            a[v[i]]++;
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}