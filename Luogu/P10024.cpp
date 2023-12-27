#include <algorithm>
#include <iostream>
using namespace std;
int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
    long long l, r;
    cin >> l >> r;
    long long delta = r - l;
    if (delta >= 10)
    {
        cout << 2 << endl;
        return 0;
    }
    int pre = 0;
    for (long long i = l; i <= r; i++)
    {
        long long now = 0, x = i;
        while (x)
        {
            now += c[x % 10];
            x /= 10;
        }
        if (pre == now)
        {
            cout << 2 << endl;
            return 0;
        }
        pre = now;
    }
    cout << 1 << endl;
    return 0;
}