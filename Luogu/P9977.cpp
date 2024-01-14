#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    long long w, c;
    bool operator<(const Node &oth) const
    {
        return w > oth.w;
    }
};
Node ns[200005];
long long n, m, k, ans;
queue<Node> q;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].w >> ns[i].c;
    }
    sort(ns + 1, ns + n + 1);
    q.push(Node{0x7f7f7f7f, m});
    for (int pos = 1; pos <= n && q.size(); pos++)
    {
        long long cost = 0;
        while (q.size() && q.front().w - ns[pos].w >= k)
        {
            Node now = q.front();
            if (now.c <= ns[pos].c)
            {
                cost += now.c, ns[pos].c -= now.c;
                q.pop();
            }
            else
            {
                cost += ns[pos].c, q.front().c -= ns[pos].c;
                break;
            }
        }
        if (cost)
        {
            ans += cost, q.push(Node{ns[pos].w, cost});
        }
    }
    cout << ans << endl;
    return 0;
}
// TAG: 贪心 模拟 优化