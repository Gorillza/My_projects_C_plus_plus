#include<iostream>
using namespace std;



int main() {
    string a;
    cin >> a;
    int asn = 0;
    if (a.size() % 2 == 0) {
        for (int i = 0; i < a.size() / 2; i++) {
            if (a[i] != a[a.size() - 1 - i]) {
                asn++;
            }
        }
    }
    else {
        for (int i = 0; i < (a.size()+1) / 2; i++) {
            if (a[i] != a[a.size() - 1 - i]) {
                asn++;
            }
        }
    }
    cout << asn;
    return 0;
}
