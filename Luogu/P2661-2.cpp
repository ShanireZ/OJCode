#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
struct Node
{
    int to, d;
};
Node nodes[200005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].to;
        nodes[nodes[i].to].d++;
    }
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (nodes[j].d == 0 && nodes[j].to != 0) //需要标记，否则会重复减去
        {
            int to = nodes[j].to;
            nodes[j].to = 0;
            nodes[to].d--;
            j = to;
        }
    }
    int mina = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i].d == 0)
        {
            continue;
        }
        int j = i, tot = 0;
        while (nodes[j].d != 0)
        {
            nodes[j].d = 0;
            tot++;
            j = nodes[j].to;
        }
        mina = min(mina, tot);
    }
    cout << mina;
    return 0;
}