#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
struct Node
{
    vector<int> ways;
    int vis, de, step; //de为度 step为当前层数
};
Node ns[100005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        ns[u].ways.push_back(v);
        ns[v].ways.push_back(u);
        ns[u].de++, ns[v].de++;
    }
    //非核心城市肯定为直径的两端内缩 度为1的点为直径两端
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].de == 1)
        {
            q.push(i);
            ns[i].step = 1;
            ns[i].vis = 1;
        }
    }
    k = n - k; //一共n-k个非核心城市
    //先找到距离为1的非核心城市 再找距离+1的...以此类推
    while (q.size())
    {
        int from = q.front();
        q.pop();
        k--;
        if (k == 0)
        {
            cout << ns[from].step;
            break;
        }
        for (int i = 0; i < ns[from].ways.size(); i++)
        {
            int to = ns[from].ways[i];
            ns[to].de--;
            if (ns[to].vis == 0 && ns[to].de == 1)
            {
                ns[to].step = ns[from].step + 1;
                q.push(to);
            }
        }
    }
    return 0;
}