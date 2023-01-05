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
    int hours, mins, sec;

    Duration()
    {
        hours = 0;
        mins = 0;
        sec = 0;
    }
    Duration(int h, int m, int s)
    {
        if (h >= 0 && m >= 0 && s >= 0)
        {
            hours = h;
            mins = m;
            sec = s;
        }
        else
        {
            cout << "Invalid values!" << endl;
            exit(0);
        }
    }
};