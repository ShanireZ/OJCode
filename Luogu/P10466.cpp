#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<long long, long long> l, r, p;
long long n, a[100005], v[100005], ans[100005][2];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[a[i]] = i, v[i] = a[i];
    }
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
    {
        l[v[i]] = v[i - 1];
        r[v[i]] = v[i + 1];
    }
    l[v[1]] = -2e15, r[v[n]] = 2e15;
    for (int i = n; i >= 2; i--)
    {
        ans[i][0] = a[i] - l[a[i]];
        ans[i][1] = p[l[a[i]]];
        if (r[a[i]] - a[i] < ans[i][0])
        {
            ans[i][0] = r[a[i]] - a[i];
            ans[i][1] = p[r[a[i]]];
        }
        r[l[a[i]]] = r[a[i]];
        l[r[a[i]]] = l[a[i]];
    }
    for (int i = 2; i <= n; i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}