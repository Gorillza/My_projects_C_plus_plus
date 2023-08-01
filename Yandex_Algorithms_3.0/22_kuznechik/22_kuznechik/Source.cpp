#include<iostream>
#include<deque>
#include<algorithm>


using namespace std;

int main() {
    long long N = 0, k = 0, sum = 0;;
    deque<long long> v;
    deque<long long> rv;
    cin >> N >> k;
    v.push_back(1);
    v.push_back(1);
    rv.push_back(1);
    rv.push_back(1);

    for (auto i = 2; i <= k; i++) {
        for (int j = 0; j < i; j++) {
            sum += v[j];
        }
        v.push_back(sum);
        rv.push_back(sum);

        sum = 0;
    }
    reverse(rv.begin(), rv.end());
    

    for (auto i = k; i < N; i++) {
        for (int j = 0; j < k; j++) {
            sum += rv[j];
        }
        rv.push_front(sum);
        sum = 0;
    }
    reverse(rv.begin(), rv.end());
    /*
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : rv) {
        cout << x << " ";
    }
    */
    cout << rv[N-1];
    return 0;
}