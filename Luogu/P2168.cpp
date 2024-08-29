#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    long long w;
    int h, id;
    bool operator<(const Node &oth) const
    {
        return (w == oth.w) ? (h > oth.h) : (w > oth.w);
    }
};
priority_queue<Node> q;
int chs[300005][15], n, k, pos;
long long w[300005], ans1, ans2;
void dfs(int now, long long sz)
{
    if (chs[now][0] == 0)
    {
        return;
    }
    for (int i = 0; i < k; i++)
    {
        ans1 += w[chs[now][i]] * (sz + 1), ans2 = max(ans2, sz + 1);
        dfs(chs[now][i], sz + 1);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        q.emplace(Node{w[i], 1, i});
    }
    pos = n;
    while ((pos - 1) % (k - 1) != 0)
    {
        q.emplace(Node{0, 1, ++pos});
    }
    while (q.size() > 1)
    {
        Node now = {0, 0, ++pos};
        for (int i = 0; i < k; i++)
        {
            Node x = q.top();
            q.pop();
            now.w += x.w, now.h = max(now.h, x.h);
            chs[now.id][i] = x.id;
        }
        now.h++;
        q.emplace(now);
    }
    dfs(q.top().id, 0);
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
// TAG: 哈夫曼树 霍夫曼树