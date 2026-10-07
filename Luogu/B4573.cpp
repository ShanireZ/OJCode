#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double t, spd, slp;
    cin >> t >> spd >> slp;
    double r = slp + 1000 / spd;
    if (abs(t - r) <= 1e-6)
    {
        cout << "tie" << endl;
    }
    else if (t < r)
    {
        cout << "turtle" << endl;
    }
    else
    {
        cout << "rabbit" << endl;
    }
    cout << fixed << setprecision(2) << r << endl;
    return 0;
}