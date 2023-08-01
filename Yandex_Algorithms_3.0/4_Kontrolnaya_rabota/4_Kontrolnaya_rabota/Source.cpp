#include<iostream>
using namespace std;

int main() {
    long long N, K, rows, colum,p,v1,v2,index=0;
    cin >> N >> K >> rows >> colum;

    if (K == N) {
        cout << -1;
        return 0;
    }
    p = (rows - 1) * 2 + colum;
    v1 = p - K;
    v2 = p + K;

    long long rows_v1, colum_v1, rows_v2, colum_v2,total;
    
    rows_v1 = v1 / 2;
    colum_v1 = v1 % 2;

    rows_v2 = v2 / 2;
    colum_v2 = v2 % 2;

    if (v2 % 2 == 0) {
        colum_v2 = 2;
    }
    else {
        rows_v2 += 1;
    }

    if (v1 % 2 == 0) {
        colum_v1 = 2;
    }
    else {
        rows_v1 += 1;
    }

    if (v1 <= 0) {
        if (v2 > N) {
            cout << -1;
            return 0;
        }
        else {
            cout << rows_v2 << " " << colum_v2;
            return 0;
        }
    }
    else {
        if (v2 > N) {
            cout << rows_v1 << " " << colum_v1;
            return 0;
        }
        else {
            if (rows - rows_v1 < rows_v2 - rows) {
                cout << rows_v1 << " " << colum_v1;
                return 0;
            }
            else {
                cout << rows_v2 << " " << colum_v2;
                return 0;
            }
        }
    }


    return 0;
}