#include <iostream>
using namespace std;
//способ нахождения НОД
int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return GreatestCommonDivisor(b, a % b);
    }
}

void reduce_fraction(int& a, int& b) {
    const int gcd = GreatestCommonDivisor(a, b);
    a = a / gcd;
    b = b / gcd;
}

int main() {
    int a, b;
    cin >> a >> b;
    reduce_fraction(a, b);
    cout << a << " " << b;
}