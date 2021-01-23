#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Line
{
    int to, len;
};
int dis[5005];
int g[5005];
vector<Line> ways[5005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        Line t1, t2;
        t1.to = b, t2.to = a;
        t1.len = t2.len = v;
        ways[a].push_back(t1);
        ways[b].push_back(t2);
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 0x3f3f3f3f;
    }
    int ans = 0, cnt = 1, last = 1;
    g[1] = 1;
    while (cnt < n)
    {
        for (int i = 0; i < ways[last].size(); i++)
        {
            int id = ways[last][i].to;
            if (g[id] == 0)
            {
                dis[id] = min(dis[id], ways[last][i].len);
            }
        }
        int min_to = 0, min_dis = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] < min_dis && g[i] == 0)
            {
                min_dis = dis[i];
                min_to = i;
            }
        }
        last = min_to;
        g[last] = 1;
        ans += min_dis;
        cnt++;
    }
    cout << ans;
    return 0;
}