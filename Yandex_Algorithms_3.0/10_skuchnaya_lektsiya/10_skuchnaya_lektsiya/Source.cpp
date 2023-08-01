#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    map<char, long long> a;
    cin >> s;
    int k = s.size();
    for (int i = 0; i < k; i ++ ) {
        a[s[i]] = a[s[i]] + (i + 1) * (k - (i + 1) + 1);
    }

    int perenos = 0;
    for (auto x : a) {
        if (perenos != 0) {
            cout << endl;
        }
        cout << x.first << ": " << x.second;
        perenos++;

    }



    /*
    string s;
    map<char, int> a;
    vector<string> vs;
    vector<string> vs_new;
    cin >>s;
    vs.push_back(s);
    int k = s.size();
    for (int i = 0; i < k-1; i++) {
        if (!s.empty()) {
            s.erase(s.begin());
        }
        vs.push_back(s);
    }

    for (auto x : vs) {
        string copy = x;
        for (int i = 0; i < x.size() - 1; i++) {
            if (!copy.empty()) {
                copy.erase(prev(copy.end()));
            }

            vs_new.push_back(copy);
        }
    }

    for (auto x : vs_new) {
        vs.push_back(x);
    }

    for (auto x : vs) {
        for (auto i : x) {
            a[i]++;
        }
    }
    int perenos = 0;
    for (auto x : a) {
        if (perenos != 0) {
            cout << endl;
        }
        cout << x.first <<": "<<x.second;
        perenos++;

    }
    */
    return 0;
}