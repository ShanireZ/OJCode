#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    string name;
    int l, r;
    bool operator<(const Node &oth) const
    {
        return (l == oth.l ? r < oth.r : l > oth.l);
    }
};
Node ns[105];
vector<Node> up, dn;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name, op;
        cin >> name >> op;
        if (op == "SAME")
        {
            ns[i] = Node{name, i, i};
        }
        else if (op == "UP")
        {
            up.push_back(Node{name, i + 1, n});
        }
        else
        {
            dn.push_back(Node{name, 1, i - 1});
        }
    }
    // 选择范围小的优先排
    sort(up.begin(), up.end());
    for (Node nd : up)
    {
        for (int i = nd.r; i >= nd.l; i--)
        {
            if (ns[i].l == 0)
            {
                ns[i] = nd;
                break;
            }
        }
    }
    sort(dn.begin(), dn.end());
    for (Node nd : dn)
    {
        for (int i = nd.l; i <= nd.r; i++)
        {
            if (ns[i].l == 0)
            {
                ns[i] = nd;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ns[i].name << endl;
    }
    return 0;
}