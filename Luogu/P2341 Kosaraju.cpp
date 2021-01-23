#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
struct Cow
{
    //usd之前是否遍历过 group强连通分量编号
    //way原图路径 rway反向图路径
    int usd, group;
    vector<int> way;
    vector<int> rway;
};
Cow cows[10005];
stack<int> stk;      //栈里保存正向深搜的后序遍历
int n, m, team;      //team强连通分量编号
int teams[10005][2]; //0强连通分量出度 1强连通分量节点个数

void dfs(int id) //正向图深搜 后序遍历入栈
{
    cows[id].usd = 1;
    for (int i = 0; i < cows[id].way.size(); i++)
    {
        int nid = cows[id].way[i];
        if (cows[nid].usd == 0)
        {
            dfs(nid);
        }
    }
    stk.push(id);
}

void rdfs(int id) //反向图深搜
{
    cows[id].usd = 1;
    cows[id].group = team;
    teams[team][1]++;
    for (int i = 0; i < cows[id].rway.size(); i++)
    {
        int nid = cows[id].rway[i];
        if (cows[nid].usd == 0)
        {
            rdfs(nid);
        }
    }
}

void kosaraju()
{
    //两个强连通分量A B 其中强连通分量A指向B
    //如果从A中元素开始遍历，则需1次DFS
    //如果从B中元素开始遍历，则需2次DFS，且每次DFS都仅会遍历分量内元素
    //我们要做的就是从被指向的强连通分量元素开始遍历，这样每次DFS出来的都是分量内的元素

    //正向图深搜后序遍历入栈 能保证被指向的强连通分量必然先入栈在栈底
    //栈顶为未被指向的强连通分量
    for (int i = 1; i <= n; i++)
    {
        if (cows[i].usd == 0)
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cows[i].usd = 0; //标记清除
    }
    //正向图中强连通分量A指向B，反向图中就会变量A被B指向，正巧A在栈顶
    //所以从栈顶开始搜索，该次搜索仅会搜索该分量的所有元素，以此类推
    while (stk.size() > 0)
    {
        int i = stk.top();
        stk.pop();
        if (cows[i].usd == 0)
        {
            rdfs(i);
            team++;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        cows[a].way.push_back(b);  //正向图
        cows[b].rway.push_back(a); //反向图
    }
    team = 1;
    kosaraju();
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