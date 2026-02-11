#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> es[50005];
long long n, m, ans, t[50005], mx[50005], cnt[50005];
queue<int> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        es[a].push_back(b), cnt[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int x : es[now])
        {
            cnt[x]--;
            mx[x] = max(mx[x], mx[now] + t[now]);
            if (cnt[x] == 0)
            {
                q.push(x);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, mx[i] + t[i]);
    }
    cout << ans << endl;
    return 0;
}