#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int a[200010], b[200010], anc[200010];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = n; i >= 1; i--)
    {
        cin >> a[i];
    }
    for (int i = m; i >= 1; i--)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= max(n, m) + 1; i++)
    {
        anc[i] += a[i] + b[i];
        anc[i + 1] += anc[i] / (i + 1);
        anc[i] %= i + 1;
    }
    int t = 0;
    for (int i = max(n, m) + 1; i >= 1; i--)
    {
        if (t || anc[i])
        {
            t = 1;
            cout << anc[i] << ' ';
        }
    }
    if (t == 0)
    {
        cout << 0 << '\n';
    }
    return 0;
}