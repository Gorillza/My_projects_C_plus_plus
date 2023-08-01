#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size() < 8) {
        cout << "NO";
        return 0;
    }
    int index1 = 0, index2 = 0, index3 = 0;
    for (auto x : s) {
        if (x >= 'A' && x <='Z') {
            index1++;
            if (index1 > 0 && index2 > 0 && index3 > 0) {
                cout << "YES";
                return 0;
            }
            continue;
        }
        if (x >= 'a' && x<='z') {
            index2++;
            if (index1 > 0 && index2 > 0 && index3 > 0) {
                cout << "YES";
                return 0;
            }
            continue;
        }
        if (isdigit(x)) {
            index3++;
            if (index1 > 0 && index2 > 0 && index3 > 0) {
                cout << "YES";
                return 0;
            }
            continue;
        }
    }
    cout << "NO";
    return 0;
}