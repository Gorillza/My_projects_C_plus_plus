#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N = 0;
    vector<long long> v;
    cin >> N;
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);
    for (int i = 3; i < N; i++) {
        v.push_back(v[i - 1] + v[i - 2] + v[i - 3]);
    }
    cout << v[N-1];
    return 0;
}