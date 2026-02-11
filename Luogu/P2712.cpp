#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> es[505];
int n, ans, cnt[505], sx[505];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int now, m, x;
        cin >> now >> m;
        sx[now] = 1;
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            es[now].push_back(x), cnt[x]++;
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        if (sx[i] && cnt[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop(), ans++;
        for (int nxt : es[now])
        {
            cnt[nxt]--;
            if (sx[nxt] && cnt[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
    if (ans == n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << n - ans << endl;
    }
    return 0;
}