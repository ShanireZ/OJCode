#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Line
{
    int d, to;
};
struct Node
{
    int d, in;
    vector<Line> ls;
};
Node ns[250005];
queue<int> pt;
char fw[5] = {'E', 'S', 'W', 'N'};
int moves[5][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int m, n;
void addline(int x, int y, char opt)
{
    if (opt == 'X')
    {
        return;
    }
    int t;
    for (int i = 0; i < 4; i++)
    {
        if (opt == fw[i])
        {
            t = i;
            break;
        }
    }
    int from = (x - 1) * n + y;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + moves[t][0];
        int ny = y + moves[t][1];
        t = (t + 1) % 4;
        if (nx < 1 || ny < 1 || nx > m || ny > n)
        {
            continue;
        }
        Line tmp;
        tmp.d = i;
        tmp.to = (nx - 1) * n + ny;
        ns[from].ls.push_back(tmp);
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char opt;
            cin >> opt;
            addline(i, j, opt);
        }
    }
    for (int i = 1; i <= m * n; i++)
    {
        ns[i].d = 0x3f3f3f3f;
    }
    ns[1].d = 0;
    ns[1].in = 1;
    pt.push(1);
    while (pt.size())
    {
        int from = pt.front();
        ns[from].in = 0;
        pt.pop();
        for (int i = 0; i < ns[from].ls.size(); i++)
        {
            int to = ns[from].ls[i].to;
            int dis = ns[from].ls[i].d;
            if (dis + ns[from].d < ns[to].d)
            {
                ns[to].d = dis + ns[from].d;
                if (ns[to].in == 0)
                {
                    ns[to].in = 1;
                    pt.push(to);
                }
            }
        }
    }
    if (ns[m * n].d == 0x3f3f3f3f)
    {
        ns[m * n].d = -1;
    }
    cout << ns[m * n].d;
    return 0;
}