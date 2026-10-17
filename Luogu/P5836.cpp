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
//如果一個區域內任意兩點相互能到達且類型一樣,那麼這個區域為一個獨立的聯通區域
//dfs搜索標記每個聯通區域 使用bfs也可
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
    //如果起點終點不在一個區域內,有兩種情況
    //1.起點終點區域的類型不同 那麼路徑上必然包含兩種牛奶
    //2.起點終點區域的類型相同 那麼必然這兩個區域被另一個類型不同的區域分隔,路徑同樣包含兩種牛奶
    //如果起點終點在同一區域內,那麼必然路徑上只有這一種牛奶
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