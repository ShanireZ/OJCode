#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> to[200005];
long long n, x, a[200005], cost[200005], rd[200005];
int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int pre;
        cin >> pre;
        if (pre != -1)
        {
            to[pre].push_back(i), rd[i]++;
        }
    }
    fill(cost + 1, cost + 1 + n, 1e18);
    for (int i = 1; i <= n; i++)
    {
        if (rd[i] == 0)
        {
            q.push(i), cost[i] = a[i];
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int nxt : to[now])
        {
            if (cost[now] + a[nxt] < cost[nxt])
            {
                q.push(nxt);
                cost[nxt] = cost[now] + a[nxt];
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (cost[i] <= x)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}