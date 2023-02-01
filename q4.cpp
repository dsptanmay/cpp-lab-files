#include <iostream>
#include <string>
using namespace std;

class Fraction
{
private:
    int num, den;

public:
    Fraction(int n, int d)
    {
        num = n;
        den = d;
    }
    Fraction()
    {
    }

    void simplify()
    {
        for (int i = 2; i <= num; i++)
        {
            if (num % i == 0 && den % i == 0)
            {
                num /= i;
                den /= i;
            }
        }
    }
    friend istream &operator>>(istream &i, Fraction &f)
    {
        i >> f.num >> f.den;
        return i;
    }
    friend ostream &operator<<(ostream &out, Fraction &f)
    {
        out << "Fraction is : " << f.num << "/" << f.den << endl;
        return out;
    }
    int operator==(Fraction &f)
    {
        float f1 = (float)num / den;
        float f2 = (float)f.num / f.den;
        if (f1 == f2)
            return 1;
        else
            return 0;
    }
    Fraction operator+(Fraction &f)
    {
        int n = f.den * num + den * f.num;
        int d = f.den * den;
        Fraction temp(n, d);
        return temp;
    }
};

int main()
{
    Fraction f1, f2;
    cout << "Enter the numerator and the denominator of the first fraction : " << endl;
    cin >> f1;
    cout << "Enter the numerator and the denominator of the second fraction : " << endl;
    cin >> f2;
    cout << f1;
    cout << f2;
    int res = f1 == f2;
    if (res == 1)
        cout << "Fractions are equal" << endl;
    else
        cout << "Fractions are not equal" << endl;
    Fraction f3 = f1 + f2;
    f3.simplify();
    cout << f3;

    return 0;
}
