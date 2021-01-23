#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> g[10005];
int outd[10005];
int fa[10005];
int dfs(int x)
{
    for (int i = 0; i < g[x].size(); i++)
    {
        int id = g[x][i];
        if (id != fa[x]) //!该边不是连接的父节点
        {
            fa[id] = x;
            outd[x] += dfs(id); //!得到每个节点的子孙节点个数
        }
    }
    return outd[x];
}
int main()
{
    ios::sync_with_stdio(false);
    int n, r, m;
    cin >> n >> r >> m;
    memset(outd, -1, sizeof(outd));
    outd[r]++;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        outd[x]++;
        outd[y]++; //!统计每个点的出度
    }
    dfs(r); //!从根节点开始遍历整个树
    for (int i = 1; i <= m; i++)
    {
        int root;
        cin >> root;
        //!点x为LCA的情况总数 = 以x为第一个点的情况数 + 以x的子孙节点为第一个点的情况数
        //!1.以x为第一个点的情况数 = 树x节点数目 = x的子孙数 + 1
        //!2.以x的子孙节点为第一个点的情况数 = 每个 (子树的节点个数 * 树中非该子树节点个数)
        //!其中 子树的节点个数 = 该子树根节点的子孙节点数 + 1
        //!其中 非该子树节点个数 = 树x子孙节点数 - 该子树根节点的子孙节点数
        int tot = outd[root] + 1;
        for (int i = 0; i < g[root].size(); i++)
        {
            int id = g[root][i];
            if (id != fa[root])
            {
                tot += (outd[id] + 1) * (outd[root] - outd[id]);
            }
        }
        cout << tot << endl;
    }
    return 0;
}