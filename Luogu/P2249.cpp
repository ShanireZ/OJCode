#include <iostream>
using namespace std;
int a[1000005];
int findx(int l, int r, int x)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) >> 1;
    if (a[mid] >= x)
    {
        return findx(l, mid, x);
    }
    else
    {
        return findx(mid + 1, r, x);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        int id = findx(1, n, x);
        if (a[id] != x)
        {
            id = -1;
        }
        cout << id << " ";
    }
    return 0;
}