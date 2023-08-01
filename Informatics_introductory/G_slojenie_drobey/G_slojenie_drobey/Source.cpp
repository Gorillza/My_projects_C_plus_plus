#include <iostream>

using namespace std;

// ���� �� �������� ���������� ����������� ������ �������� (���) � �����������:
// ������ ����� ������� ����� �������� ���� ��, �� � ������� �����������
long long GreatestCommonDivisor(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    else {
        return GreatestCommonDivisor(b, a % b);
    }
}

class Fraction {
public:
    Fraction() {  // ����� �� ��������� � 0/1
        numerator = 0;
        denominator = 1;
    }
    Fraction(long long new_numerator, long long new_denominator) {
        const long long gcd = GreatestCommonDivisor(new_numerator, new_denominator);
        // �������� �����, �������� ��������� � ����������� �� �� ���
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        // ����������� ������ ���� �������������
    }

    long long Numerator() const {
        return numerator;
    }

    long long Denominator() const {
        return denominator;
    }

    void show() {
        cout << numerator << '/' << denominator;
    }

    Fraction operator + ( const Fraction& rhs) {
        return {
            Numerator() * rhs.Denominator() + rhs.Numerator() * Denominator(),
            Denominator() * rhs.Denominator()
        };
    }


    void read() {
        long long n, d;
        char c;
        if (cin) {
            cin >> n >> c >> d;
            numerator = n;
            denominator = d;
        }
    }

private:
    long long numerator;
    long long denominator;
};


int main() {
    Fraction u, v;
    u.read();
    v.read();
    (u + v).show();
}