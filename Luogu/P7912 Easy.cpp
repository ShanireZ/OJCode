#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node
{
    int v, st, ed;
    Node(int V, int St, int Ed)
    {
        v = V, st = St, ed = Ed;
    }
};
vector<Node> ns;
int main()
{
    int n;
    scanf("%d", &n);
    int now = -1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == now)
        {
            ns[ns.size() - 1].ed = i;
        }
        else
        {
            ns.push_back(Node(x, i, i));
            now = x;
        }
    }
    while (ns.size())
    {
        int now = abs(ns[0].v - 1);
        for (int i = 0; i < ns.size(); i++)
        {
            if (now == ns[i].v)
            {
                continue;
            }
            printf("%d ", ns[i].st);
            ns[i].st++;
            now = ns[i].v;
        }
        printf("\n");
        for (int i = ns.size() - 1; i >= 0; i--)
        {
            if (ns[i].st > ns[i].ed)
            {
                ns.erase(ns.begin() + i);
            }
        }
    }
    return 0;
}