#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

// test 1 : fheriherffazfszkisrrs       answer 2 
// test 2 : rifftratatashe              answer 1
// test 3 : sheriffsheriffsheriff       answer 3
// test 4 : sherifsherifsherif          answer 1
// test 5 : sherifsherifsherifsherif    answer 2

int main() {
    char s;
    
    unordered_map<char, long long>m;
    while (cin>>s) {//�������� ������ ����� ��������� 
        m[s]++;
    }

    long long min_one_char = 2000000000;
    string l = "sheri";
    for (auto i : l) {
        min_one_char = min(min_one_char, m[i]);
    }

    //������ � ���������� �� ����� ����������� ����������
    // ���� �� ���� ��������� ������� �� �������

    long long ff = m['f'];
    // ������ � ff �������� ����� �������� f

    if (ff <= 1 || min_one_char == 0) {// ��������� ������������� ���������
        cout << 0;
        return 0;
    }

    if (ff % 2 == 0) {//���� ����� ������ ����� �� ���
        ff = ff / 2;
    }
    else {// ���� ����� �� ������ �� �������� 1 � ����� �� ���
        --ff;
        ff = ff / 2;
    }
    // ������ � ff �������� ����� ���� ������� �� ����� ��������� ����� ff

    cout << min(ff, min_one_char);
    return 0;
}