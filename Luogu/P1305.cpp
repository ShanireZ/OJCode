#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int l, r, p;
};
Node tree[30];
int check[30];
int n;
void traversal(int num)
{
    cout << char('a' + num - 1);
    Node node = tree[num];
    if (node.l != 0)
    {
        traversal(node.l);
    }
    if (node.r != 0)
    {
        traversal(node.r);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        int pos = (tmp[0] - 'a') + 1;
        check[pos] = 1;
        if (tmp[1] != '*')
        {
            int pos_l = (tmp[1] - 'a') + 1;
            tree[pos].l = pos_l;
            tree[pos_l].p = pos;
        }
        if (tmp[2] != '*')
        {
            int pos_r = (tmp[2] - 'a') + 1;
            tree[pos].r = pos_r;
            tree[pos_r].p = pos;
        }
    }
    int root;
    for (int i = 1; i <= 26; i++)
    {
        if (tree[i].p == 0 && check[i])
        {
            root = i;
            break;
        }
    }
    traversal(root);
    return 0;
}