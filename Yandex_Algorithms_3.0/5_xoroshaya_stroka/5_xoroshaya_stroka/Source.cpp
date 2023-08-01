#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

vector<long long> pref_vectot(vector<long long>& pref) {
    vector<long long> result;
    result.push_back(0);
    long long sum = 0;
    for (int i = 0;i<pref.size();i++) {
        sum += pref[i];
        result.push_back(sum);
    }
    return result;
}

long long min_vector(vector<long long>& pref) {
    set<long long> result;
    long long min = 0;
    for (int i = 0; i < pref.size(); i++) {
        result.insert(pref[i]);
    }

    return *result.begin();
}


long long kute_string(vector<long long>& k) {
    long long result = 0;
    long long pref_max = *prev(pref_vectot(k).end());//мб из за этого
    if (pref_max == 0 || k.size() <= 1) {
        return result;
    }

    long long minimal = min_vector(k);
    result += minimal*(k.size() - 1);

    for (auto& x : k) {
        x -= minimal;
    }


    vector<long long> left, right;
    bool z = true;
    for (auto i = k.begin(); i < k.end(); i++) {
        if (*i == 0 && z) {
            z = false;
            continue;
        }
        if (z) {
            left.push_back(*i);
        }
        else {
            right.push_back(*i);
        }
    }


    result += kute_string(left) + kute_string(right);

    return result;
}

int main() {
    long long N;
    cin >> N;
    long long k = 0;
    vector<long long> ks;
    for (int i = 0; i < N; i ++ ) {
        cin >> k;
        ks.push_back(k);
    }

    long long sum = kute_string(ks);
    cout << sum;
    return 0;
}
