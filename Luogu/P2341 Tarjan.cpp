#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct Cow
{
    //low子树能到达的最小dfn点 dfn深搜的顺序号 in是否在栈中 group强连通分量编号
    int low, dfn, in, group;
    vector<int> way; //子节点
};
Cow cows[10005];
stack<int> stk;
int n, m, idx, team; //idx深搜的顺序号 team强连通分量编号
int teams[10005][2]; //0强连通分量出度 1强连通分量节点个数
void tarjan(int id)
{
    stk.push(id);
    cows[id].dfn = cows[id].low = idx++;
    cows[id].in = 1;
    for (int i = 0; i < cows[id].way.size(); i++)
    {
        int nid = cows[id].way[i];
        if (cows[nid].dfn == 0) //没访问过的节点
        {
            tarjan(nid);
            cows[id].low = min(cows[id].low, cows[nid].low);
        }
        else if (cows[nid].in == 1) //访问过且在栈里 说明是现在路线上的点而不是别的路线上的点
        {
            cows[id].low = min(cows[id].low, cows[nid].dfn);
        }
    }
    if (cows[id].low == cows[id].dfn) //形成环
    {
        int nid;
        do
        {
            nid = stk.top();
            cows[nid].in = 0;
            cows[nid].group = team;
            teams[team][1]++;
            stk.pop();
        } while (nid != id);
        team++;
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        cows[a].way.push_back(b);
    }
    team = idx = 1;
    for (int i = 1; i <= n; i++)
    {
        if (cows[i].dfn == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) //计算各强连通分量的出度
    {
        for (int j = 0; j < cows[i].way.size(); j++)
        {
            if (cows[cows[i].way[j]].group != cows[i].group)
            {
                teams[cows[i].group][0]++;
            }
        }
    }
    //找到出度为0的强连通分量 那里的奶牛全是明星
    //如果有2各，那么说明没有明星，因为他们都没有喜欢对象，所以就不会有奶牛收到全部喜欢
    int zero = 0;
    for (int i = 1; i < team; i++)
    {
        if (teams[i][0] == 0)
        {
            if (zero == 0)
            {
                zero = i;
            }
            else
            {
                cout << 0;
                return 0;
            }
        }
    }
    cout << teams[zero][1];
    return 0;
}