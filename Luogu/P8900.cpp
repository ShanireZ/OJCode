#include <iostream>
#include <vector>
using namespace std;
vector<int> to[200005];
int n, cnt, upos, dpos;
long long avg, gs[200005], up[200005][3], down[200005][3];
void dfs(int now, int fa)
{
    for (int i = 0; i < int(to[now].size()); i++)
    {
        int nxt = to[now][i];
        if (nxt != fa)
        {
            dfs(nxt, now);
        }
    }
    if (gs[now] > avg)
    {
        up[++upos][0] = now, up[upos][1] = fa, up[upos][2] = gs[now] - avg;
    }
    else if (gs[now] < avg)
    {
        down[++dpos][0] = fa, down[dpos][1] = now, down[dpos][2] = avg - gs[now];
    }
    cnt += (gs[now] != avg), gs[fa] += gs[now] - avg, gs[now] = avg;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> gs[i];
        avg += gs[i];
    }
    avg /= n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b), to[b].push_back(a);
    }
    dfs(1, 0);
    cout << cnt << "\n";
    for (int i = 1; i <= upos; i++)
    {
        cout << up[i][0] << " " << up[i][1] << " " << up[i][2] << "\n";
    }
    for (int i = dpos; i >= 1; i--)
    {
        cout << down[i][0] << " " << down[i][1] << " " << down[i][2] << "\n";
    }
    return 0;
}