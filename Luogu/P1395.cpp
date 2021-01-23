#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    vector<int> ways;
    int size, vis;
};
Node ns[50005];
int mindis, minpos = 1, n;
void build(int now, int step)
{
    ns[now].size++;
    ns[now].vis = 1;
    if (step)
    {
        mindis += step;
    }
    for (int i = 0; i < ns[now].ways.size(); i++)
    {
        int to = ns[now].ways[i];
        if (ns[to].vis == 0)
        {
            build(to, step + 1);
            ns[now].size += ns[to].size;
        }
    }
    ns[now].vis = 0;
}
void dfs(int now, int sz)
{
    ns[now].vis = 1;
    int dis = sz - ns[now].size + (n - ns[now].size);
    if (dis < mindis)
    {
        mindis = dis;
        minpos = now;
    }
    else if (dis == mindis && minpos > now)
    {
        minpos = now;
    }
    for (int i = 0; i < ns[now].ways.size(); i++)
    {
        int to = ns[now].ways[i];
        if (ns[to].vis == 0)
        {
            dfs(to, dis);
        }
    }
    ns[now].vis = 0;
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ns[x].ways.push_back(y);
        ns[y].ways.push_back(x);
    }
    build(1, 0);
    int sz1 = mindis;
    ns[1].vis = 1;
    for (int i = 0; i < ns[1].ways.size(); i++)
    {
        int to = ns[1].ways[i];
        dfs(to, sz1);
    }
    cout << minpos << " " << mindis;
    return 0;
}