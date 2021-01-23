#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    double x;
    cin >> x;
    double speed = 2, s = 0;
    int day = 0;
    while (s < x)
    {
        day++;
        s += speed;
        speed *= 0.98;
    }
    cout << day;
}