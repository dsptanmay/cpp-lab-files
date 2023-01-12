//

#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;
class RainGauge
{
private:
    double rainfallincm;
    char cityName[80];

public:
    void fnReadMeasurement()
    {
        cout << "Enter City Name: ";
        cin.getline(cityName, 80);
        srand(unsigned(time(0)));
        rainfallincm = (double)rand() / (RAND_MAX) + 1 + (rand() % 20);
    }
    void fnDispReading()
    {
        cout << "City Name: " << cityName << endl;
        cout << "Rainfall : " << rainfallincm << endl;
    }
    void friend averageRain(int n, RainGauge obj[])
    {
        double average;
        for (int i = 0; i < n; i++)
        {
            average += obj->rainfallincm;
        }
        average = average / n;
        cout << "Average Rainfall received = " << average;
    }
};
int main()
{
    RainGauge obj[10];
    for (int j = 0; j < 10; j++)
    {
        obj[j].fnReadMeasurement();
    }
    for (int j = 0; j < 10; j++)
    {
        cout << "\nCity " << j + 1 << " details:"
             << endl;
        obj[j].fnDispReading();
    }
    averageRain(10, obj);
    return 0;
}