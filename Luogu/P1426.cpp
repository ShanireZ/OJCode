#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    double s, x, v = 7;
    cin >> s >> x;
    while (s - x > 0)
    {
        s -= v;
        v = v * 0.98;
    }
    s += x;
    if (s >= v)
    {
        cout << "y" << endl;
    }
    else
    {
        cout << "n" << endl;
    }
    return 0;
}