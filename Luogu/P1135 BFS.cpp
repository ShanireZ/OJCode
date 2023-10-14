#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct QK
{
    int ceng, step;
};
queue<QK> q;
int k[205], vis[205];
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    q.push(QK{a, 0}), vis[a] = 1;
    while (q.size())
    {
        int now = q.front().ceng, s = q.front().step;
        q.pop();
        if (now == b)
        {
            cout << s << endl;
            return 0;
        }
        int nxt = now + k[now];
        if (nxt <= n && vis[nxt] == 0)
        {
            q.push(QK{nxt, s + 1}), vis[nxt] = 1;
        }
        nxt = now - k[now];
        if (nxt >= 1 && vis[nxt] == 0)
        {
            q.push(QK{nxt, s + 1}), vis[nxt] = 1;
        }
    }
    cout << -1 << endl;
    return 0;
}