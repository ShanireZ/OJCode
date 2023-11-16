#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int c[15];
    for (int i = 1; i <= 10; i++)
    {
        cin >> c[i];
    }
    double jg[15] = {0, 28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
    double tot = 0;
    for (int i = 1; i <= 10; i++)
    {
        tot += jg[i] * c[i];
    }
    cout << fixed << setprecision(1) << tot << endl;
    return 0;
}