#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, a, b, t;
    cin >> x >> a >> b >> t;
    if (x < 60)
    {
        cout << 0 << endl;
    }
    else if (x < 120)
    {
        cout << a << endl;
    }
    else if (x < 240)
    {
        cout << b << endl;
    }
    else
    {
        cout << t << endl;
    }
    return 0;
}