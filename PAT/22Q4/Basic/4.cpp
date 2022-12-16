#include <iostream>
using namespace std;
int da[10], db[10];
int gcd(int x, int y)
{
    int r = x % y;
    while (r)
    {
        x = y, y = r, r = x % y;
    }
    return y;
}
int cf(int x, int d[10])
{
    int pos = 0;
    while (x)
    {
        d[++pos] = x % 10, x /= 10;
    }
    return pos;
}
int zh(int sz, int d[10])
{
    int ans = 0;
    for (int i = sz; i > 0; i--)
    {
        if (d[i] != -1)
        {
            ans = ans * 10 + d[i];
        }
    }
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int pa = cf(a, da), pb = cf(b, db);
    for (int i = pa; i > 0; i--)
    {
        for (int j = pb; j > 0; j--)
        {
            if (da[i] == db[j])
            {
                da[i] = db[j] = -1;
                break;
            }
        }
    }
    int na = zh(pa, da), nb = zh(pb, db);
    int g1 = gcd(a, b), g2 = (nb == 0) ? 1 : gcd(na, nb); // nb有可能为0
    cout << a << "/" << b << " ";
    if (a / g1 != na / g2 || b / g1 != nb / g2)
    {
        cout << "!";
    }
    cout << "= " << na << "/" << nb << endl;
    return 0;
}