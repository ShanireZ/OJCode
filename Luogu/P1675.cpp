#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int v, id;
};
Node ns[200];
bool cmp(Node x, Node y)
{
    return x.v > y.v;
}
int main()
{
    int k;
    cin >> k;
    for (int i = 1; i <= k * 3; i++)
    {
        cin >> ns[i].v;
        ns[i].id = i;
    }
    sort(ns + 1, ns + 1 + k * 3, cmp);
    while (true)
    {
        random_shuffle(ns + 1, ns + 1 + k * 2);
        int tot1 = 0, tot2 = 0;
        for (int i = 1; i <= k; i++)
        {
            tot1 += ns[i].v;
        }
        if (tot1 <= 500 * k)
        {
            continue;
        }
        for (int i = k + 1; i <= k * 2; i++)
        {
            tot2 += ns[i].v;
        }
        if (tot2 > 500 * k)
        {
            for (int i = 1; i <= k * 3; i++)
            {
                cout << ns[i].id << '\n';
            }
            break;
        }
    }
    return 0;
}
// TAG: 贪心 随机算法