#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> all;
int a[505], b[505], c[505] = {1}, sza, szb, szc = 1;
void mul(int x)
{
    int p = 0;
    while (x)
    {
        a[p++] = x % 10;
        x /= 10;
    }
    sza = p - 1;
    szb = szc;
    memcpy(b, c, sizeof(b));
    memset(c, 0, sizeof(c));
    for (int i = 0; i <= sza; i++)
    {
        for (int j = 0; j <= szb; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i <= 500; i++)
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
        if (c[i] != 0)
        {
            szc = i;
        }
    }
}
int main()
{
    int n, x = 2;
    cin >> n;
    for (int i = 2; n >= i; i++)
    {
        n -= i;
        all.push_back(i);
    }
    int ex = n / all.size(), p = all.size() - 1;
    n %= all.size();
    while (n)
    {
        all[p]++;
        p--, n--;
    }
    for (int i = 0; i < all.size(); i++)
    {
        cout << all[i] + ex << " ";
        mul(all[i] + ex);
    }
    cout << endl;
    for (int i = szc; i >= 0; i--)
    {
        cout << c[i];
    }
    return 0;
}