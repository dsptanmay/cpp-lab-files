/*
 Write a C++ program that stores the time duration in hh:mm:ss format in a class called Duration having
the members hh, mm and ss.
*/

// zero parameter constructor that sets all data members to zero
// three parameter constructor that sets values of hh, mm and ss respectively if the values are valid
#include <iostream>
#include <cmath>
using namespace std;

class Duration
{
private:
    int hh, mm, ss;

public:
    Duration()
    {
        hh = mm = ss = 0;
    }
    Duration(int h, int m, int s)
    {
        hh = h;
        mm = m;
        ss = s;
    }

    void getDuration()
    {
        int temp;
        while (1)
        {
            cout << "Enter the number of hours: ";
            cin >> temp;
            if (temp < 0)
            {
                cout << "Invalid Value!";
            }
            else
            {
                hh = temp;
                break;
            }
        }
        while (1)
        {
            cout << "Enter the number of minutes: ";
            cin >> temp;
            if (temp < 0)
            {
                cout << "Invalid Value!";
            }
            else
            {
                mm = temp;
                break;
            }
        }
        while (1)
        {
            cout << "Enter the number of seconds: ";
            cin >> temp;
            if (temp < 0)
            {
                cout << "Invalid Value!";
            }
            else
            {
                ss = temp;
                break;
            }
        }
    }
    void showDuration()
    {
        cout << "Duration: " << hh << ":" << mm << ":" << ss << endl;
    }

    void friend addDuration(Duration &d1, Duration &d2)
    {
        cout << "Hours added  : " << d1.hh << "+" << d2.hh << "=" << d1.hh + d2.hh << endl;
        cout << "Minutes added: " << d1.mm << "+" << d2.mm << "=" << d1.mm + d2.mm << endl;
        cout << "Seconds added: " << d1.ss << "+" << d2.ss << "=" << d1.ss + d2.ss << endl;
    }
};

int main()
{
    Duration d1, d2;
    d1.getDuration();
    d2.getDuration();
    addDuration(d1, d2);
    return 0;
}