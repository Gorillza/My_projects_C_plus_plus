#include<iostream>
#include<map>
using namespace std;

int main() {
    string s;
    map<char, int> a;
    int maxsum = 0;

    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            a[s[i]]++;
            if (a[s[i]] > maxsum) {
                maxsum = a[s[i]];
            }
        }
    }

    for (int i = maxsum; i > 0; i--) {
        for (auto x : a) {
            if (x.second >= i) {
                cout << "#";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (auto y : a) {
        cout << y.first;
    }
    return 0;
}
