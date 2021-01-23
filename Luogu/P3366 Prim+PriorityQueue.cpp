#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Line
{
    int to, len;
};
struct cmp
{
    bool operator()(Line a, Line b)

    {
        return a.len > b.len;
    }
};
vector<Line> ls[5005];
int g[5005];
priority_queue<Line, vector<Line>, cmp> q;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        Line t1, t2;
        t1.to = b;
        t2.to = a;
        t1.len = t2.len = v;
        ls[a].push_back(t1);
        ls[b].push_back(t2);
    }
    int ans = 0, cnt = 1, last = 1;
    g[1] = 1;
    while (cnt < n)
    {
        for (int i = 0; i < ls[last].size(); i++)
        {
            if (g[ls[last][i].to] == 0)
            {
                q.push(ls[last][i]);
            }
        }
        while (g[q.top().to] == 1)
        {
            q.pop();
        }
        last = q.top().to;
        g[last] = 1;
        ans += q.top().len;
        cnt++;
        q.pop();
    }
    cout << ans;
    return 0;
}