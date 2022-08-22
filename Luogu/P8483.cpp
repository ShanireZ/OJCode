#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int id;
    long long v, mul;
    bool operator<(const Node oth) const
    {
        return v > oth.v;
    }
};
priority_queue<Node> q;
queue<int> q1, q2;
int pos, a, b, base[200005][3], vis[200005], his[1000005][2];
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> base[i][0] >> base[i][1] >> base[i][2];
        ans += base[i][0] + base[i][1] + base[i][2];
        q.push(Node{i, base[i][0] * 4 + base[i][1] * 2 + base[i][2], 3});
        vis[i] = 1;
    }
    for (int i = 1; i <= n - 2; i++)
    {
        Node tp = q.top();
        q.pop();
        vis[tp.id]++;
        ans += tp.v;
        q.push(Node{tp.id, base[tp.id][0] * tp.mul * tp.mul + base[tp.id][1] * tp.mul + base[tp.id][2], tp.mul + 1});
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
        {
            q1.push(i);
        }
        else
        {
            q2.push(i);
        }
    }
    for (int i = 1; i <= n - 2; i++)
    {
        his[++pos][0] = q2.front();
        his[pos][1] = q1.front();
        q1.pop();
        vis[q2.front()]--;
        if (vis[q2.front()] == 1)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    his[++pos][0] = q1.front();
    q1.pop();
    his[pos][1] = q1.front();
    q1.pop();
    for (int i = 1; i <= m - n + 1; i++)
    {
        Node a = q.top();
        q.pop();
        Node b = q.top();
        q.pop();
        ans += a.v + b.v;
        his[n + i - 1][0] = a.id;
        his[n + i - 1][1] = b.id;
        q.push(Node{a.id, a.mul * a.mul * base[a.id][0] + a.mul * base[a.id][1] + base[a.id][2], a.mul + 1});
        q.push(Node{b.id, b.mul * b.mul * base[b.id][0] + b.mul * base[b.id][1] + base[b.id][2], b.mul + 1});
    }
    cout << ans << '\n';
    for (int i = 1; i <= m; i++)
    {
        cout << his[i][0] << " " << his[i][1] << '\n';
    }
    return 0;
}