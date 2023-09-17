#include <cstring>
#include <iostream>
using namespace std;
long long cnt;
int n, a[500005], tmp[500005];
void dfs(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    dfs(l, mid), dfs(mid + 1, r);
    for (int i = l, p1 = l, p2 = mid + 1; i <= r; i++)
    {
        if ((p1 <= mid && p2 <= r && a[p1] <= a[p2]) || p2 > r)
        {
            tmp[i] = a[p1++];
        }
        else
        {
            cnt += (mid + 1 - p1), tmp[i] = a[p2++];
        }
    }
    memcpy(a + l, tmp + l, sizeof(int) * (r - l + 1));
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, n);
    cout << cnt << endl;
    return 0;
}