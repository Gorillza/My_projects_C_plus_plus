/*#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
private:
    int num_rows_;
    int num_columns_;
    int k;
    vector<vector<int>> elements_;

public:
    Matrix() {
        num_rows_ = 0;
        num_columns_ = 0;
    }

    Matrix(int num_rows, int num_columns) {
        Reset(num_rows, num_columns);
    }

    void Reset(int num_rows, int num_columns) {
        if (num_rows < 0) {
            throw out_of_range("num_rows must be >= 0");
        }
        if (num_columns < 0) {
            throw out_of_range("num_columns must be >= 0");
        }
        if (num_rows == 0 || num_columns == 0) {
            num_rows = num_columns = 0;
        }

        num_rows_ = num_rows;
        num_columns_ = num_columns;
        elements_.assign(num_rows, vector<int>(num_columns));
    }

    int& At(int row, int column) {
        return elements_.at(row).at(column);
    }

    int At(int row, int column) const {
        return elements_.at(row).at(column);
    }

    int GetNumRows() const {
        return num_rows_;
    }

    int GetNumColumns() const {
        return num_columns_;
    }

};

bool operator==(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        return false;
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        return false;
    }

    for (int row = 0; row < one.GetNumRows(); ++row) {
        for (int column = 0; column < one.GetNumColumns(); ++column) {
            if (one.At(row, column) != two.At(row, column)) {
                return false;
            }
        }
    }

    return true;
}

Matrix operator+(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        throw invalid_argument("Mismatched number of rows");
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        throw invalid_argument("Mismatched number of columns");
    }

    Matrix result(one.GetNumRows(), one.GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int column = 0; column < result.GetNumColumns(); ++column) {
            result.At(row, column) = one.At(row, column) + two.At(row, column);
        }
    }

    return result;
}

istream& operator>>(istream& in, Matrix& matrix) {
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int column = 0; column < matrix.GetNumColumns(); ++column) {
            in >> matrix.At(row, column);
        }
    }

    return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
    out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int column = 0; column < matrix.GetNumColumns(); ++column) {
            if (column > 0) {
                out << " ";
            }
            out << matrix.At(row, column);
        }
        out << endl;
    }

    return out;
}

int main() {
    int num_rows, num_colum, K;
    cin >> num_rows >> num_colum >> K;
    Matrix one(num_rows, num_colum);
    cin >> one;
    int x1, y1, x2, y2;
    bool z = false;
    long long sum = 0;
    while (K != 0) {
        if (z) {
            cout << endl;
        }
        cin >> x1 >> y1 >> x2 >> y2;
        for (int row = x1-1; row < x2; ++row) {
            for (int column = y1-1; column < y2; ++column) {
                sum+=one.At(row, column);
            }
        }
        cout << sum;
        sum = 0;
        z = true;
        K--;

    }


    return 0;
}*/
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long N, M, K, L, sum = 0;
    cin >> N >> M >> K;
    //вектор для префиксных сумм
    vector<long long> pref_sum;
    //матрица для хранения элементов
    vector<vector<long long>> pref_matrix;

    for (int i = 0; i < N; i++) {
        pref_sum.push_back(0);
        for (int j = 0; j < M; j++) {
            cin >> L;
            sum += L;
            pref_sum.push_back(sum);
        }
        pref_matrix.push_back(pref_sum);
        pref_sum.clear();
        sum = 0;
    }
    /*
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            cout << matrix.at(i).at(j);
        }
    }
    cout << endl;
    for (int i = 0; i < pref_matrix.size(); i++) {
        for (int j = 0; j < pref_matrix.at(i).size(); j++) {
            cout << pref_matrix.at(i).at(j)<<" ";
        }
        cout << endl;
    }
    */
    
    //анализ матрицы
    int x1, x2, y1, y2,z = 0;
    long long result = 0;
    while (z<K) {
        if (z != 0) {
            cout << endl;
        }
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1-1; i < x2; i++) {
            result += (pref_matrix.at(i).at(y2) - pref_matrix.at(i).at(y1-1));
            //cout << pref_matrix.at(i).at(y2) << " " << pref_matrix.at(i).at(y1) << endl;
        }
        z++;
        cout << result;
        result = 0;
    }
    
    //вывод матрицы
    /*
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            cout << matrix.at(i).at(j);
        }
    }
    */

    return 0;
}