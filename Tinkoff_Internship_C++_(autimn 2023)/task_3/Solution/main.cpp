#include<iostream>
#include<vector>
#include<algorithm>;
using namespace std;

int main() {
    long long N = 0;
    cin >> N;//����������� ��������
    long long ai = 0 , bi =0;
    vector<long long>a;
    vector<long long>b;
    //���� ������
    for (int i = 0; i < N; i++) {
        cin >> ai;
        a.push_back(ai);
    }
    for (int i = 0; i < N; i++) {
        cin >> bi;
        b.push_back(bi);
    }

    //��������� ��� ������� ��������� ������� �� ��������
    vector<long long> z;
    auto j = 0;
    for (auto i = 0; i < a.size(); i++) {
        if (a[i] != b[j]) {
            z.push_back(i);
        }
        j++;
    }

    //������� ������
    if (z.size() == 0) {
        cout << "YES";
        return 0;
    }


    long long i = *z.begin();
    long long k = *prev(z.end());

    //�������� �������� �� ������ ������ �� �������� �� ������ �������
    sort(a.begin() + i, a.begin() + 1 + k);

    //�������� �� ���������
    if (a == b) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    
    return 0;
}