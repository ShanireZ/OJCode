#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Node
{
    char type;
    int area;
    vector<int> links;
};
Node nodes[100005];
//如果一个区域内任意两点相互能到达且类型一样,那么这个区域为一个独立的联通区域
//dfs搜索标记每个联通区域 使用bfs也可
void make_area(int root, int group)
{
    nodes[root].area = group;
    for (int i = 0; i < nodes[root].links.size(); i++)
    {
        int nid = nodes[root].links[i];
        if (nodes[nid].area == 0 && nodes[nid].type == nodes[root].type)
        {
            make_area(nid, group);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].type;
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a].links.push_back(b);
        nodes[b].links.push_back(a);
    }
    int g = 1;
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i].area == 0)
        {
            make_area(i, g++);
        }
    }
    //如果起点终点不在一个区域内,有两种情况
    //1.起点终点区域的类型不同 那么路径上必然包含两种牛奶
    //2.起点终点区域的类型相同 那么必然这两个区域被另一个类型不同的区域分隔,路径同样包含两种牛奶
    //如果起点终点在同一区域内,那么必然路径上只有这一种牛奶
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        char ch;
        cin >> a >> b >> ch;
        if (nodes[a].area == nodes[b].area && nodes[a].type != ch)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }
    return 0;
}