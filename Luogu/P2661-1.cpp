#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int step, to, vis;
};
Node nodes[200005];
int ans = 0x3f3f3f3f;
void dfs(int x, int step)
{
    if (nodes[x].vis)
    {
        return;
    }
    if (nodes[x].step)
    {
        ans = min(ans, step - nodes[x].step);
    }
    else
    {
        nodes[x].step = step;
        dfs(nodes[x].to, step + 1);
        nodes[x].vis = 1;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].to;
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 1);
    }
    cout << ans;
    return 0;
}