#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <iomanip>
using namespace std;

//������� ��� ������ ������� �������
long double F(long double x) {
    long double R1 = sin((pow(x, 2) * 5 + x - 4) / 5);
    long double R2 = cosh((pow(x, 3) + 3 * pow(x, 2) + 5 * x + 8) / (3 * x + 9));
    long double VarF = R1 + R2 - 1.0;
    return VarF;
}

//����� 1:������� ��� ������ �������� � ��������� ����� ������� �� eps
long double SearchMin(long double a, long double b, long double eps , map<long double, pair<long double, long double>>& a_m) {
    long double xMin = a, fMin = F(a);
    long double i = 1;
    while (a <= b) {
        if (F(a) < fMin) {
            xMin = a;
            fMin = F(a);
        }
        a_m[i] = make_pair(a, F(a));
        a += eps;
        i++;
    }
    return xMin;
}

//����� 2.1:������� ��� ������ ��������� ������� ���������
long double Dexotomiya(long double a, long double b, long double eps, map<long double, pair<long double, long double>>& a_m) {

    long double del = eps / 2 - eps / 4;
    long double m = (a + b) / 2;
    long double i = 1;
    a_m[i] = make_pair(a, b);
    while (abs(b - a) > eps) {

        m = (a + b) / 2.;

        long double x1 = m - del;
        long double x2 = m + del;

        if (F(x1) > F(x2)) {
            a = x1;
        }
        else {
            b = x2;
        }
        i++;
        a_m[i] = make_pair(a, b);
        if (i > 380) {
            break;
        }
    }
    cout << endl;
    cout << "Metod dexetomii klichestvo iteraciy : " << i << endl;
    return m;
}

//����� 2.2:������� ��� ������ ��������� ������� �������� �������
long double Zoloto(long double a, long double b, long double eps, map<long double, pair<long double, long double>>& a_m) {

    long double tau = (sqrt(5.) + 1.) / 2.;
    long double x1, x2;
    long double i = 1;
    a_m[i] = make_pair(a, b);
    while (abs(b - a) > eps)
    {
        x1 = b - (b - a) / tau;
        x2 = a + (b - a) / tau;
        if (F(x1) > F(x2)) {
            a = x1;
        }
        else {
            b = x2;
        }
        i++;
        a_m[i] = make_pair(a, b);
        if (i > 500) {
            break;
        }
    }

    cout << endl;
    cout << "Metod zoloto klichestvo iteraciy : " << i << endl;

    return x1;
}

//����� 2.3:������� ��� ������ �������� ������� ��������������� ����������� ������������
long double kvadrat(long double a, long double b, long double eps, map<long double, pair<long double, long double>>& a_m) {
    long double m = (a + b) / 2;
    long double i = 1;
    long double x1 = a;
    long double x2 = m;
    long double x3 = b;
    long double x = 0;

    while (abs(x3 - x1) > eps) {
        long double f1 = F(x1);
        long double f2 = F(x2);
        long double f3 = F(x3);
        x = (f1 * (pow(x2, 2) - pow(x3, 2)) - f2 * (pow(x1, 2) - pow(x3, 2)) + f3 * (pow(x1, 2) - pow(x2, 2)));
        x/= (2 * (f1 * (x2 - x3) - f2 * (x1 - x3) + f3 * (x1 - x2)));

        //��� ������ ������ ��������
        if (i == 1) {
            a_m[i] = make_pair(x, x);
        }

        if ((x >= x2) && (x <= x3)) {
            x1 = x2;
            x2 = x;
        }
        else {
            x3 = x2;
            x2 = x;
        }
        i++;
        a_m[i] = make_pair(x, x);

        if (i > 380) {
            break;
        }
    }
    cout << endl;
    cout << "Metod kvadrata klichestvo iteraciy : " << i << endl;

    return x;
}

int main() {
    //��������, ����������� � ������:
    long double a = -1, b = 0, eps, x_o, x_d, x_z, x_k;
    map<long double, pair<long double, long double>> a_o, a_d, a_z, a_k;
    int razryad = 17;// ����� ������������ � ����� ��������� ����� ��������� � ������� ����� 
    cout << "interval: -1 0" << endl;
    cout << "pogreshnost: ";
    cout << setprecision(razryad)<<fixed;// ��������� ����������� �������� ����� � �������
    //cin >> eps;
    //eps = 0.01;
    //eps = 0.0001;
    //eps = 0.0000001;
     eps = pow(0.1,17);
    cout << eps<<endl;
    
    //��� ������� e17 � e7 ����� ������������� ������ �����
    //����� �������:
    /*
    cout << "Metod razdelenia otrezla" << endl;
    x_o = SearchMin(a, b, eps,a_o);
    cout << "x = " << x_o << endl;
    cout << "f(x) = " << F(x_o) << endl << endl;

    //������� ����� ��� ������ ������
    ofstream fanc_x("razdelenie_x.txt");
    ofstream fanc_fx("razdelenie_Fx.txt");

    cout << fixed;
    cout << setprecision(razryad);
    //������ ������ � �������������� ����� ����� ������
    for (const auto& k : a_o) {
        fanc_fx << k.second.second << " ";
        fanc_x << k.second.first << " ";
    }
    */

    //����� ���������
    cout << "Metod dexetomii" << endl;
    x_d = Dexotomiya(a, b, eps, a_d);
    cout << "x = " << x_d << endl;
    cout << "f(x) = " << F(x_d) << endl << endl;

    //������� ����� ��� ������ ������
    ofstream output1("Dexotomiya_left.txt");
    ofstream output2("Dexotomiya_right.txt");
    ofstream output("Dexotomiya_int.txt");

    cout << fixed;
    cout << setprecision(razryad);
    //������ ������ � �������������� ����� ����� ������
    for (const auto& k : a_d) {
        output << k.first << " ";
        output1 << k.second.first << " ";
        output2 << k.second.second << " ";
    }

    //����� �������� �������
    cout << "Metod zolotogo sechenia" << endl;
    x_z = Zoloto(a, b, eps, a_z);
    cout << "x = " << x_z << endl;
    cout << "f(x) = " << F(x_z) << endl << endl;

    //������� ����� ��� ������ ������
    ofstream o1("Zoloto_left.txt");
    ofstream o2("Zoloto_right.txt");
    ofstream o("Zoloto_int.txt");

    cout << fixed;
    cout << setprecision(razryad);
    //������ ������ � �������������� ����� ����� ������
    for (const auto& k : a_z) {
        o << k.first << " ";
        o1 << k.second.first << " ";
        o2 << k.second.second << " ";
    }

    //����� ��������������� ����������� ������������
    cout << "Metod posledovatelnoy kvadrotichnoy aproksimacii" << endl;
    x_k = kvadrat(a, b, eps, a_k);
    cout << "x = " << x_k << endl;
    cout << "f(x) = " << F(x_k) << endl;

    //������� ����� ��� ������ ������
    ofstream oo1("kvadrat_left.txt");
    ofstream oo2("kvadrat_right.txt");
    ofstream oo("kvadrat_int.txt");

    //������ ������ � �������������� ����� ����� ������
    for (const auto& k : a_k) {
        oo << k.first << " ";
        oo1 << k.second.first << " ";
        oo2 << k.second.second << " ";
    }
    return 0;
}