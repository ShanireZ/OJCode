#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        int b = pow(a, 0.25);
        if (b * b * b * b == a)
        {
            cout << b << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}