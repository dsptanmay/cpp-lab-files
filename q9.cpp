#include <iostream>
#include <cmath>
using namespace std;

class Matrix
{
private:
    unsigned int m, n;
    float **arr;

public:
    Matrix(int rows, int columns)
    {
        m = rows;
        n = columns;
        arr = new float *[m];
        for (int i = 0; i < m; i++)
        {
            arr[i] = new float[n];
        }
    }

    int operator==(Matrix &Mat)
    {
        if ((m == Mat.m) && (n == Mat.n))
        {
            return 1;
        }
        return 0;
    }

    Matrix operator+(Matrix &Mat)
    {
        Matrix temp(m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.arr[i][j] = arr[i][j] + Mat.arr[i][j];
            }
        }
        return temp;
    }

    Matrix operator-(Matrix &Mat)
    {
        Matrix temp(m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.arr[i][j] = arr[i][j] - Mat.arr[i][j];
            }
        }
        return temp;
    }

    friend istream &operator>>(istream &in, Matrix &Mat)
    {
        for (int i = 0; i < Mat.m; i++)
        {
            for (int j = 0; j < Mat.n; j++)
            {
                in >> Mat.arr[i][j];
            }
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, Matrix &Mat)
    {
        for (int i = 0; i < Mat.m; i++)
        {
            for (int j = 0; j < Mat.n; j++)
            {
                out << Mat.arr[i][j] << "\t";
            }
            out << endl;
        }
        return out;
    }
};

int main(int argc, const char *argv[])
{
    int m1, n1, m2, n2, choice;
    cout << "Enter the number of rows and columns of Matrix 1: " << endl;
    cin >> m1 >> n1;
    cout << "Enter the number of rows and columns of Matrix 2: " << endl;
    cin >> m2 >> n2;

    Matrix mat1(m1, n1), mat2(m2, n2);
    cout << "Enter " << m1 * n1 << " elements for matrix 1:" << endl;
    cin >> mat1;
    cout << "Enter " << m2 * n2 << " elements for matrix 2:" << endl;
    cin >> mat2;

    while (1)
    {
        cout << "1.Display Both Matrices" << endl;
        cout << "2.Add Matrices and show result" << endl;
        cout << "3.Subtract Matrices and show result" << endl;
        cout << "4.EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Matrix 1:" << endl;
            cout << mat1;
            cout << "Matrix 2:" << endl;
            cout << mat2;
            break;
        case 2:
            if (mat1 == mat2)
            {
                Matrix M3 = mat1 + mat2;
                cout << M3;
                break;
            }
            else
            {
                cout << "Matrices are not of same dimensions!" << endl;
                break;
            }

        case 3:
            if (mat1 == mat2)
            {
                Matrix M3 = mat1 - mat2;
                cout << M3;
                break;
            }
            else
            {
                cout << "Matrices are not of same dimensions!" << endl;
                break;
            }
        
        case 4:
            return 0;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    }

    return 0;
}