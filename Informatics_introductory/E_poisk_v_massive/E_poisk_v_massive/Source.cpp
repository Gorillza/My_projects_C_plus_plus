#include <iostream>
using namespace std;

int arrayFind(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a[100], n, x;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    cout << arrayFind(a, n, x);
}