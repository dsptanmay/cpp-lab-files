/*Write a C++ program to create a class to represent entities of type Circle, specified by its attributes
radius and coordinates of its center. Include appropriate Constructors and display methods. Also write
a friend function that determines whether two circles intersect one another or they touch each other or
they are disjoint*/

#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
private:
    float rad;
    float x;
    float y;

public:
    Circle()
    {
        cout << "Enter the radius of the circle(float): " << endl;
        cin >> rad;
        cout << "Enter the coordinates of the circle: " << endl;
        cin >> x >> y;
    }

    void display()
    {
        cout << "Coordinates of circle are: (" << x << "," << y << ")" << endl;
    }
    ~Circle() {}

    friend void intersect(Circle &, Circle &);
};

void intersect(Circle &c1, Circle &c2)
{
    float dist;
    float a = pow((c1.x - c2.x), 2);
    float b = pow((c1.y - c2.y), 2);
    dist = sqrt(a + b);
    if (dist > (c1.rad + c2.rad))
    {
        cout << "Circles are disjoint" << endl;
    }
    else if (dist == (c1.rad + c2.rad))
    {
        cout << "Circles touch each other" << endl;
    }
    else
    {
        cout << "Circles intersect each other" << endl;
    }
}

int main()
{
    Circle c1, c2;
    c1.display();
    c2.display();
    intersect(c1, c2);
    return 0;
}