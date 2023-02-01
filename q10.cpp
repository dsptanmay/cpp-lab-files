#include <iostream>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

class Matrix{
    private:
        unsigned int m,n;
        float **arr;
    public:
        Matrix(int rows, int columns){
            m = rows;
            n = columns;
            arr = new float *[m];
            for(int i=0;i<m;i++)
                arr[i] = new float[n];

        }
        int operator==(Matrix& Mat){
            if(n==Mat.m)
                return 1;
            return 0;
        }

        Matrix operator*(Matrix &Mat){
            Matrix temp(m,Mat.n);
            for(int i=0;i<m;i++){
                for(int j=0;j<Mat.n;j++){
                    temp.arr[i][j] = 0;
                    for(int k=0;k<n;k++){
                        temp.arr[i][j] = arr[i][k]*Mat.arr[k][j];
                    }
                }
            }

            return temp;
        }

        friend ostream& operator<<(ostream& out, Matrix& Mat){
            for(int i=0;i<Mat.m;i++){
                for(int j=0;j<Mat.n;j++){
                    out << Mat.arr[i][j] << "\t";
                }
                out << endl;
            }

            return out;
        }

        friend istream& operator>>(istream& ist, Matrix& Mat){
            for(int i=0;i<Mat.m;i++){
                for(int j=0;j<Mat.n;j++){
                    ist >> Mat.arr[i][j];
                }
            }
            return ist;
        }
};

int main(){
    int m1,n1,m2,n2;
    cout << "Enter the number of rows and columns of Matrix 1:" << endl;
    cin >> m1 >> n1;

    cout << "Enter the number of rows and columns of Matrix 2:" << endl;
    cin >> m2 >> n2;

    Matrix M1(m1,n1), M2(m2,n2);

    cout << "Enter the elements of Matrix 1:" << endl;
    cin >> M1;
    cout << "Enter the elements of Matrix 2:" << endl;
    cin >> M2;

    Matrix M3 = M1*M2;
    cout << "Elements  of Matrix 3 are:" << endl;
    cout << M3;
    return 0;
}
