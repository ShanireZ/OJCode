#include <algorithm>
#include <iostream>
using namespace std;
int read(), a[100005], b[100005], maxn[100005], minn[100005];
int main()
{
    int k = read();
    while (k--)
    {
        int n;
        cin >> n;
        maxn[0] = -1, minn[n + 1] = 2e9;
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i] = read();
            maxn[i] = max(maxn[i - 1], a[i]);
        }
        for (int i = n; i >= 1; i--)
        {
            minn[i] = min(minn[i + 1], a[i]);
        }
        sort(b + 1, b + 1 + n);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += (a[i] == b[i] && maxn[i] <= a[i] && minn[i] >= a[i]);
        }
        int fst = (a[1] == b[1] && minn[1] >= a[1]), lst = (a[n] == b[n] && maxn[n] <= a[n]);
        cnt >= 3 || (cnt == 2 && (lst || fst)) ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}
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