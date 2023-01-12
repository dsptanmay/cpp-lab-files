#include <iostream>
#include <cmath>

using namespace std;

class Fraction
{
private:
    int num, den;

public:
    void simplify(){
        for(int i=2;i<=num;i++){
            if(num%i==0 && den%i==0 ){
                num = num/i;
                den = den/i;
            } 
        }
    }

    void operator>>(Fraction &f)
    {
        cout << "Enter value of numerator:" << endl;
        cin >> f.num;
        cout << "Enter value of denominator:" << endl;
        cin >> f.den;
    }
    void operator<<(Fraction &f)
    {
        cout << "Fraction is: " << f.num << "/" << f.den << endl;
    }

    int operator==(Fraction &f1)
    {
        float x = f1.num / f1.den;
        float y = num / den;
        if (x == y)
        {
            return 1;
        }
        return 0;
    }
    Fraction operator+(Fraction &f1)
    {
        Fraction temp;
        float x, y;
        x = f1.num * den + num * f1.den;
        y = f1.den * den;

        temp.num = x;
        temp.den = y;
        return temp;
    }
};

int main()
{
    Fraction f1, f2;
}