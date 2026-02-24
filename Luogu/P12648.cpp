#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct Node
{
    long long pos, dis;
    bool operator<(const Node &oth) const
    {
        return dis > oth.dis;
    }
};
priority_queue<Node> q;
map<long long, int> vis;
long long l, n, k, p, cnt;
int main()
{
    cin >> l >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        q.push(Node{p, 0});
    }
    while (cnt < k)
    {
        long long now = q.top().pos, dis = q.top().dis;
        q.pop();
        if (vis[now])
        {
            continue;
        }
        cout << dis << endl;
        vis[now] = 1, cnt++;
        if (now - 1 >= 0 && vis[now - 1] == 0)
        {
            q.push(Node{now - 1, dis + 1});
        }
        if (now + 1 <= l && vis[now + 1] == 0)
        {
            q.push(Node{now + 1, dis + 1});
        }
    }
    return 0;
}