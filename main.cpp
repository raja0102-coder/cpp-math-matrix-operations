#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<double>> data;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<double>(c, 0.0)) {}

    void setElement(int r, int c, double val) {
        data[r][c] = val;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            cout << "    [ ";
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << "]\n";
        }
    }

    // Matrix Addition Operator Overloading (+)
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Matrix Multiplication Operator Overloading (*)
    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Transpose function
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

int main() {
    cout << "==================================================\n";
    cout << "    SEM 2 ENGINEERING MATH: C++ MATRIX ENGINE     \n";
    cout << "==================================================\n\n";

    // 1. Initialize Matrices A & B (2x2)
    Matrix A(2, 2);
    A.setElement(0, 0, 1); A.setElement(0, 1, 2);
    A.setElement(1, 0, 3); A.setElement(1, 1, 4);

    Matrix B(2, 2);
    B.setElement(0, 0, 5); B.setElement(0, 1, 6);
    B.setElement(1, 0, 7); B.setElement(1, 1, 8);

    cout << "[1] MATRIX A:\n";
    A.display();
    cout << "\n[2] MATRIX B:\n";
    B.display();

    // 2. Matrix Addition
    cout << "\n[3] MATRIX ADDITION (A + B):\n";
    Matrix sum = A + B;
    sum.display();

    // 3. Matrix Multiplication
    cout << "\n[4] MATRIX MULTIPLICATION (A * B):\n";
    Matrix prod = A * B;
    prod.display();

    // 4. Matrix Transpose
    cout << "\n[5] TRANSPOSE OF MATRIX A:\n";
    Matrix trans = A.transpose();
    trans.display();

    cout << "\n==================================================\n";

    return 0;
}
