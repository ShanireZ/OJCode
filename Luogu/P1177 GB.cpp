#include <cstring>
#include <iostream>
using namespace std;
int a[100005], tmp[100005];
void dfs(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    dfs(l, mid), dfs(mid + 1, r);
    int p1 = l, p2 = mid + 1;
    for (int i = l; i <= r; i++)
    {
        if ((p1 <= mid && p2 <= r && a[p1] <= a[p2]) || p2 > r)
        {
            tmp[i] = a[p1++];
        }
        else
        {
            tmp[i] = a[p2++];
        }
    }
    memcpy(a + l, tmp + l, sizeof(int) * (r - l + 1));
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}