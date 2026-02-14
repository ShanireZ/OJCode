#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> f;
long long a[505][505], t[505][505], n, k, ans;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int u = 1, v = 2, len, pre, ok = 0;
    t[u][v] = 1, f.push_back(u);
    for (long long i = 2; i <= k; i++)
    {
        swap(u, v);
        v = a[u][v];
        if (t[u][v] != 0)
        {
            len = i - t[u][v], pre = t[u][v] - 1, ok = 1;
            break;
        }
        t[u][v] = i, f.push_back(u);
    }
    if (ok == 0)
    {
        cout << f.back() << endl;
        return 0;
    }
    k = (k - pre) % len + pre;
    if (k == 0)
    {
        k = len;
    }
    cout << f[k - 1] << endl;
    return 0;
}