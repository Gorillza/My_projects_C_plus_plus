#include<iostream>

using namespace std;

int main() {

    long long N,sum = 0;
    long long old = 0, n = 0;
    bool f = false;
    cin >> old;
    while (cin >> n) {
        if (n == 0) {
            cout << sum;
            return 0;
        }
        if (n > old) {
            sum++;
        }
        old = n;

    }

    return 0;
}