#include <iostream>
#include <vector>
using namespace std;
vector<int> es[10005];
int usd[10005], b[1000005];
bool dfs(int now, int tag)
{
    if (usd[now] == tag)
    {
        return 0;
    }
    usd[now] = tag;
    for (int i = 0; i < es[now].size(); i++)
    {
        int to = es[now][i];
        if (b[to] == 0 || dfs(b[to], tag))
        {
            b[to] = now;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        es[a].push_back(i);
        es[b].push_back(i);
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (dfs(i, i) == 0)
        {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << 10000 << endl;
    return 0;
}