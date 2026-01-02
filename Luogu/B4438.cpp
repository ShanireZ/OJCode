#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= 30 && a <= 70)
    {
        cout << a << endl;
    }
    else if ((b >= 30 && b <= 70) || (c >= 30 && c <= 70))
    {
        int x = (b >= 30 && b <= 70 ? b : c);
        if (c >= 30 && c <= 70)
        {
            x = min(x, c);
        }
        cout << x << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}