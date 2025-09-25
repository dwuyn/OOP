#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> data;

public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        data.assign(rows, vector<int>(cols, 0));
    }

    void input() {
        cout << "input matrix: " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) 
                cin >> data[i][j];
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << "\n";
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw runtime_error("cannot add different size matrix");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw runtime_error("cannot sub different size matrix");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) 
            throw runtime_error("cannot mul matrix: cols A != rows B");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int m, n, p, q;
    cout << "input rows and cols of matrix A: ";
    cin >> m >> n;
    Matrix A(m, n);
    A.input();

    cout << "input rows and cols of matrix B: ";
    cin >> p >> q;
    Matrix B(p, q);
    B.input();

    cout << "\nadd: \n";
    (A+B).print();
    cout << "\n";

    cout << "\nsub: \n";
    (A-B).print();
    cout << "\n";

    cout << "\nmul: \n";
    (A*B).print();
    cout << "\n";

    return 0;
}
