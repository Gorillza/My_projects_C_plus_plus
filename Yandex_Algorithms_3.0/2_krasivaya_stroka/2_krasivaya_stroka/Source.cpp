#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    long long b = 26, k = 0;
    cin >> k;
    long long K = k, ks = 0, maxans = 0;
    string s;
    cin >> s;
    char  a = 'a';
    vector<long long> v;
    vector<long long> v1;
    for (int i = 0; i < 25; i++) {//для переключения буквы 
        int d = 0;
        for (int j = 0; j < s.size(); j++) {//левый указатель
            while (k >= 0 && d < s.size()) {//правый указател
                if (s[d] != a) {
                    k--;
                }
                if (k != -1) {
                    ks = d - j;
                }
                if (ks > maxans) {
                    maxans = ks;
                }
                d++;
            }
            if (s[j] != a) {
                k++;
            }
        }
        a++;
        k = K;
    }

    cout <<maxans+1;
    return 0;
}