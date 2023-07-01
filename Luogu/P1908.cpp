#include <cstring>
#include <iostream>
using namespace std;
int a[500005], tmp[500005];
long long ans;
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
long long mergesort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergesort(l, mid), mergesort(mid + 1, r);
    int p1 = l, p2 = mid + 1;
    for (int i = l; i <= r; i++)
    {
        (p1 <= mid && p2 <= r && a[p1] <= a[p2] || p2 > r) ? (tmp[i] = a[p1++]) : (ans += mid - p1 + 1, tmp[i] = a[p2++]);
    }
    memcpy(a + l, tmp + l, sizeof(int) * (r - l + 1));
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    mergesort(1, n);
    printf("%lld\n", ans);
    return 0;
}