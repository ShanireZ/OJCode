#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int lc[1000005], rc[1000005];
void dfs1(int now)
{
    cout << now << " ";
    if (lc[now])
    {
        dfs1(lc[now]);
    }
    if (rc[now])
    {
        dfs1(rc[now]);
    }
}
void dfs2(int now)
{
    if (lc[now])
    {
        dfs2(lc[now]);
    }
    cout << now << " ";
    if (rc[now])
    {
        dfs2(rc[now]);
    }
}
void dfs3(int now)
{
    if (lc[now])
    {
        dfs3(lc[now]);
    }
    if (rc[now])
    {
        dfs3(rc[now]);
    }
    cout << now << " ";
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lc[i] >> rc[i];
    }
    dfs1(1);
    cout << endl;
    dfs2(1);
    cout << endl;
    dfs3(1);
    cout << endl;
    return 0;
}