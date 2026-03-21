#include <algorithm>
#include <iostream>
using namespace std;
int l[100005], r[100005], wq[100005], m[100005], h[100005], n, ans;
void dfs(int now)
{
    if (l[now])
    {
        dfs(l[now]);
    }
    if (r[now])
    {
        dfs(r[now]);
    }
    h[now] = max(h[l[now]], h[r[now]]) + 1;
    if (m[l[now]] && m[r[now]] && h[l[now]] == h[r[now]])
    {
        m[now] = 1;
    }
    if (wq[l[now]] && wq[r[now]])
    {
        if (m[l[now]] && h[l[now]] - h[r[now]] == 0)
        {
            wq[now] = 1;
        }
        else if (m[r[now]] && h[l[now]] - h[r[now]] == 1)
        {
            wq[now] = 1;
        }
    }
    ans += wq[now];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    wq[0] = m[0] = 1;
    dfs(1);
    cout << ans << endl;
    return 0;
}