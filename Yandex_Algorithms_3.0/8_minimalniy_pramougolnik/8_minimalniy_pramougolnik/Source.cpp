#include<iostream>  
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int k = 0;
    vector<int> all_x;
    vector<int> all_y;
    cin >> k;
    int x = 0;
    int y = 0;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        all_x.push_back(x);
        all_y.push_back(y);
    }

    sort(all_x.begin(), all_x.end());
    sort(all_y.begin(), all_y.end());

    cout << all_x[0] << " " << all_y[0] << " " << all_x[all_x.size() - 1] << " " << all_y[all_y.size() - 1];
    return 0;
}