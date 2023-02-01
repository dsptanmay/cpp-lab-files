#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Polygon{
    protected:
        string name;
        int numSides;
        float area;
    public:
        void display(){
            cout << "Name of Polygon: " << name << endl;
            cout << "Number of Sides: " << numSides << endl;
            cout << "Area of Polygon: " << area << endl;
        }
    virtual void calcArea()=0;
};

class Triangle: public Polygon{
    public:
        Triangle(){
            name = "Triangle";
            numSides = 3;
        }
        void calcArea(){
            int a,b,c;
            float s;
            cout << "Enter 3 sides of the Triangle: " << endl;
            cin >> a >> b >> c;
            s = (a+b+c)/2.0;
            float r = s*(s-a)*(s-b)*(s-c);
            float res = sqrt(r);
            area = res;
            cout << "Area of Triangle is : " << res << endl;
            return;
        }
};

class Square: public Polygon{
    public:
        Square(){
            name = "Square";
            numSides = 1;
        }
        void calcArea(){
            float n;
            cout << "Enter the side of the square: " << endl;
            cin >> n;
            area = n*n;
            cout << "Area of Square is : " << area << endl;
            return;
        }
};
int main(){
    Triangle t;
    t.calcArea();
    Square s;
    s.calcArea();
    t.display();
    s.display();
    return 0;
}
