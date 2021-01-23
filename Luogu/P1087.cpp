#include <iostream>
#include <cmath>
using namespace std;
struct Node
{
    char type;
    int l, r;
};
Node tree[2048];
void traversal(Node node)
{
    if (node.l != 0)
    {
        traversal(tree[node.l]);
    }
    if (node.r != 0)
    {
        traversal(tree[node.r]);
    }
    cout << node.type;
}
int main()
{
    int n;
    cin >> n;
    for (int i = pow(2, n); i < pow(2, n + 1); i++)
    {
        char tmp;
        cin >> tmp;
        if (tmp == '0')
        {
            tree[i].type = 'B';
        }
        else
        {
            tree[i].type = 'I';
        }
    }
    for (int i = pow(2, n) - 1; i > 0; i--)
    {
        tree[i].l = 2 * i;
        tree[i].r = 2 * i + 1;
        if (tree[tree[i].l].type == tree[tree[i].r].type)
        {
            tree[i].type = tree[tree[i].l].type;
        }
        else
        {
            tree[i].type = 'F';
        }
    }
    traversal(tree[1]);
    return 0;
}