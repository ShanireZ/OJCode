#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int d;
    cin >> d;
    double bike = 50 + d / 3.0;
    double walk = d / 1.2;
    if (bike == walk)
    {
        cout << "All" << endl;
    }
    else if (bike < walk)
    {
        cout << "Bike" << endl;
    }
    else
    {
        cout << "Walk" << endl;
    }
    return 0;
}