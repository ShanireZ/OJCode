#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a1, b1, a2, b2, a3, b3, c;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> c;
    int bmx = max({b1, b2, b3});
    int c1 = a1 + c * (b1 - bmx);
    int c2 = a2 + c * (b2 - bmx);
    int c3 = a3 + c * (b3 - bmx);
    if (c1 <= c2 && c1 <= c3)
    {
        cout << 1 << " " << c1 << endl;
    }
    else if (c2 < c1 && c2 <= c3)
    {
        cout << 2 << " " << c2 << endl;
    }
    else
    {
        cout << 3 << " " << c3 << endl;
    }
    return 0;
}