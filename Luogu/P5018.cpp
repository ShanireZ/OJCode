#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int value;
    int lc, rc;
};
Node tree[1000005];
int n, max_node = 1, total, trig;

void check(int lc, int rc)
{
    if (lc == -1 && rc == -1)
    {
        return;
    }
    if (lc == -1 || rc == -1 || tree[lc].value != tree[rc].value)
    {
        trig = 0;
        return;
    }
    total += 2;
    check(tree[lc].rc, tree[rc].lc);
    if (trig == 0) //可省略
    {
        return;
    }
    check(tree[lc].lc, tree[rc].rc);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i].value;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i].lc >> tree[i].rc;
    }
    for (int i = 1; i <= n; i++)
    {
        if (tree[i].lc != -1 && tree[i].rc != -1 &&
            tree[tree[i].lc].value == tree[tree[i].rc].value)
        {
            trig = 1, total = 1;
            check(tree[i].lc, tree[i].rc);
            if (trig)
            {
                max_node = max(max_node, total);
            }
        }
    }
    cout << max_node;
    return 0;
}