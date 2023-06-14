#include <algorithm>
#include <iostream>
using namespace std;
int a[10005], b[10005], c[10005];
int main()
{
    int d = 2, k1, k2;
    cin >> k1;
    for (int i = k1; i >= 1; i--)
    {
        cin >> a[i];
        d = max(d, a[i] + 1);
    }
    cin >> k2;
    for (int i = k2; i >= 1; i--)
    {
        cin >> b[i];
        d = max(d, b[i] + 1);
    }
    int sz = max(k1, k2);
    for (int i = 1; i <= sz; i++)
    {
        c[i] += a[i] + b[i];
        if (c[i] >= d)
        {
            c[i] -= d, c[i + 1]++;
        }
    }
    sz += (c[sz + 1] != 0);
    cout << sz;
    for (int i = sz; i >= 1; i--)
    {
        cout << " " << c[i];
    }
    return 0;
}