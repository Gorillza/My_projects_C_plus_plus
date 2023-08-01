#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<utility>

#include<stack>

using namespace std;

int main() {
    long long N,a = 0,min = 0;
    stack<pair<long long, long long>>v1;


    cin >> N;
    vector<long long>v2(N, -1);
    vector<long long> ve;
    for (auto i = 0; i < N; i++) {
        cin >> a;
        
        while (!v1.empty() && v1.top().first > a) {
            v2[v1.top().second] = i;
            v1.pop();
        }
        
        v1.push(make_pair(a,i));
    }

    bool f = false;
    for (auto x : v2) {
        if (f) {
            cout << " ";
        }
        cout << x;
        f = true;
    }

    return 0;
}
