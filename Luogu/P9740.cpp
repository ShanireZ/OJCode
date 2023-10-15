#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int a[10], b[10];
int main()
{
    int n, au, now = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        a[i] = 100 / a[i], b[i] = b[i] * a[i];
        now += b[i];
    }
    cin >> au;
    if (now >= au)
    {
        cout << "Already Au." << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (now + (100 - b[i]) < au)
        {
            cout << "NaN" << endl;
        }
        else
        {
            cout << ceil((au - now) * 1.0 / a[i]) << endl;
        }
    }
    return 0;
}