#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int fw, x, y, fa, id, sz; //fw0向北 fw1向东
    vector<int> ch;
};
Node cows[1005];
bool cmp(Node a, Node b)
{
    if (a.fw == b.fw)
    {
        if (a.fw == 0)
        {
            return a.x < b.x;
        }
        else
        {
            return a.y < b.y;
        }
    }
    return a.fw < b.fw;
}
bool cmpid(Node a, Node b)
{
    return a.id < b.id;
}
void update(int id)
{
    for (int i = 0; i < cows[id].ch.size(); i++)
    {
        int to = cows[id].ch[i];
        update(to);
        cows[id].sz += cows[to].sz;
    }
}
int main()
{
    int n, north = 0, east = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char op;
        cin >> op >> cows[i].x >> cows[i].y;
        if (op == 'N')
        {
            cows[i].fw = 0;
            north++;
        }
        else
        {
            cows[i].fw = 1;
            east++;
        }
        cows[i].id = i;
        cows[i].sz = 1;
    }
    sort(cows + 1, cows + 1 + n, cmp);
    for (int i = 1; i <= north; i++)
    {
        for (int j = north + 1; j <= n; j++)
        {
            if (cows[i].fa != 0 || cows[j].fa != 0)
            {
                continue;
            }
            if (cows[i].x >= cows[j].x && cows[i].y <= cows[j].y)
            {
                if (cows[i].x - cows[j].x > cows[j].y - cows[i].y)
                {
                    cows[j].fa = cows[i].id;
                    cows[i].ch.push_back(cows[j].id);
                }
                else if (cows[i].x - cows[j].x < cows[j].y - cows[i].y)
                {
                    cows[i].fa = cows[j].id;
                    cows[j].ch.push_back(cows[i].id);
                }
            }
        }
    }
    sort(cows + 1, cows + 1 + n, cmpid);
    for (int i = 1; i <= n; i++)
    {
        if (cows[i].fa == 0)
        {
            update(i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << cows[i].sz - 1 << endl;
    }
    return 0;
}