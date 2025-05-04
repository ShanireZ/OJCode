#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int lc, rc, cnt, tag;
    long long jv, ov;
};
vector<Node> ns;
long long mod = 1000000000, q, pre;
void edit(int now, int l, int r, int x)
{
    if (l == r)
    {
        swap(ns[now].jv, ns[now].ov), ns[now].cnt++;
        pre % 2 ? ns[now].ov += x : ns[now].jv += x;
        return;
    }
    if (ns[now].tag)
    {
        ns[now].tag = 0;
        swap(ns[ns[now].lc].jv, ns[ns[now].lc].ov), ns[ns[now].lc].tag ^= 1;
        swap(ns[ns[now].rc].jv, ns[ns[now].rc].ov), ns[ns[now].rc].tag ^= 1;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        if (ns[now].lc == 0)
        {
            ns.push_back(Node{0, 0, 0, 0, 0, 0});
            ns[now].lc = ns.size() - 1;
        }
        edit(ns[now].lc, l, mid, x);
        swap(ns[ns[now].rc].jv, ns[ns[now].rc].ov), ns[ns[now].rc].tag ^= 1;
    }
    else
    {
        if (ns[now].rc == 0)
        {
            ns.push_back(Node{0, 0, 0, 0, 0, 0});
            ns[now].rc = ns.size() - 1;
        }
        pre += ns[ns[now].lc].cnt;
        edit(ns[now].rc, mid + 1, r, x);
    }
    ns[now].cnt++;
    ns[now].jv = ns[ns[now].lc].jv + ns[ns[now].rc].jv;
    ns[now].ov = ns[ns[now].lc].ov + ns[ns[now].rc].ov;
}
int main()
{
    ns.push_back(Node{0, 0, 0, 0, 0, 0}); // ns[0]
    ns.push_back(Node{0, 0, 0, 0, 0, 0}); // ns[1]
    cin >> q;
    while (q--)
    {
        long long y;
        cin >> y;
        y = (ns[1].jv + y) % mod + 1, pre = 0;
        edit(1, 1, 1000000000, y);
        cout << ns[1].jv << endl;
    }
    return 0;
}