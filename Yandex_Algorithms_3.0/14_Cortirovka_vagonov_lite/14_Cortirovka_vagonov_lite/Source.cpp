#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    long long N,sum = 0;
    vector<int> st1;
    vector<int> st2;
    vector<int> tupik;

    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> sum;
        st1.push_back(sum);
    }
    int i = 0;
    while (true) {

        while (true) {
            if (!st1.empty()) {
                if (st1[0] == i + 1) {
                    st2.push_back(st1[0]);
                    st1.erase(st1.begin());
                    i++;
                    break;
                }
                else {
                    if (!tupik.empty()) {
                        if (tupik[tupik.size() - 1] == i + 1) {
                            st2.push_back(tupik[tupik.size() - 1]);
                            tupik.pop_back();
                            i++;
                            break;
                        }
                        else {
                            tupik.push_back(st1[0]);
                            st1.erase(st1.begin());
                        }
                    }
                    else {
                        tupik.push_back(st1[0]);
                        st1.erase(st1.begin());
                    }
                }
            }
            else {
                if (!tupik.empty()) {
                    if (tupik[tupik.size() - 1] == i + 1) {
                        st2.push_back(tupik[tupik.size() - 1]);
                        tupik.pop_back();
                        i++;
                        break;
                    }
                    else {
                        cout << "NO";
                        return 0;
                    }
                }
                else {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }



    return 0;
}