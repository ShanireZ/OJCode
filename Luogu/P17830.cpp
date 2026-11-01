#include <algorithm>
#include <iostream>
using namespace std;
#define MX 500005
int n, m, a[MX], t[MX], lst[MX], pre[MX];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        t[i] = 1;
        if (pre[i])
        {
            t[i] += t[pre[i]];
        }
        if (i > 1 && lst[a[i - 1]] == i - 1)
        {
            t[i] += t[i - 1];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << t[lst[i]] << " ";
    }
    cout << endl;
    return 0;
}