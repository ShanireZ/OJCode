#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int a, b, id;
};
Node ns[200005], ns2[200005];
struct cmp11
{
    bool operator()(Node x, Node y)
    {
        return x.b < y.b;
    }
};
priority_queue<Node, vector<Node>, cmp11> q11;
struct cmp22
{
    bool operator()(Node x, Node y)
    {
        return x.id > y.id;
    }
};
priority_queue<Node, vector<Node>, cmp22> q22;
bool cmp1(Node x, Node y)
{
    return x.a == y.a ? x.b < y.b : x.a > y.a;
}
bool cmp2(Node x, Node y)
{
    return x.b == y.b ? x.a < y.a : x.b < y.b;
}
int main()
{
    int n, c, f;
    cin >> n >> c >> f;
    for (int i = 1; i <= c; i++)
    {
        cin >> ns[i].a >> ns[i].b;
    }
    sort(ns + 1, ns + c + 1, cmp1); // 选分高的n/2+1个
    for (int i = 1; i <= c; i++)
    {
        ns[i].id = i;
        ns2[i] = ns[i];
    }
    sort(ns2 + 1, ns2 + c + 1, cmp2); // 选钱少的n/2个
    int pre = 0, suf = 0;
    for (int i = 1, j = 1; i + n / 2 <= c && j <= c;)
    {
        if ((int)q11.size() == n / 2 + 1)
        {
            pre -= q11.top().b;
            q11.pop();
        }
        while ((int)q11.size() < n / 2 + 1 && i + n / 2 <= c)
        {
            pre += ns[i].b;
            q11.push(ns[i]);
            i++;
        }
        while (q22.size() && q22.top().id < i)
        {
            suf -= q22.top().b;
            q22.pop();
        }
        while ((int)q22.size() < n / 2 && j <= c)
        {
            if (ns2[j].id >= i)
            {
                q22.push(ns2[j]);
                suf += ns2[j].b;
            }
            j++;
        }
        if (q11.size() + q22.size() == n && pre + suf <= f)
        {
            cout << ns[i - 1].a << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}