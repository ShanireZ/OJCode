#include <algorithm>
#include <iostream>
using namespace std;
int q, pos;
string n, m, a[1000005];
int main()
{
    cin >> n >> m >> q;
    while (pos < q && n != m)
    {
        int x = n[n.size() - 1] - '0';
        n = n.substr(0, n.size() - 1);
        if (x != 0)
        {
            n = char(x * x % 10 + '0') + n;
        }
        a[++pos] = n;
    }
    if (n == m)
    {
        for (int i = 1; i <= pos; i++)
        {
            cout << a[i] << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}