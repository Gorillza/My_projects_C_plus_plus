#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main() {
    int N = 0;
    int k = 0;
    int sum = 0;
    int j = 0;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> k;
        if (k > j) {
            j = k;
        }
        v.push_back(k);
    }
    cout << accumulate(v.begin(),v.end(),0) - j;
    return 0;
}