#include <cstdio>
#include <set>
using namespace std;
struct Node
{
    int l, r, v; //v表示状态 1工作 0不工作
    Node(int L, int R, int V)
    {
        l = L, r = R, v = V;
    }
    bool operator<(const Node &another) const
    {
        return l < another.l;
    }
};
set<Node> st;
int tot;
set<Node>::iterator split(int pos)
{
    set<Node>::iterator it = st.lower_bound(Node(pos, 0, 0));
    if (it != st.end() && it->l == pos)
    {
        return it;
    }
    it--;
    int l = it->l, r = it->r, v = it->v;
    st.erase(it);
    st.insert(Node(l, pos - 1, v));
    return st.insert(Node(pos, r, v)).first;
}
void edit(int l, int r, int status)
{
    set<Node>::iterator itr = split(r + 1);
    set<Node>::iterator itl = split(l);
    for (set<Node>::iterator it = itl; it != itr; it++)
    {
        tot += (status - it->v) * (it->r - it->l + 1);
    }
    st.erase(itl, itr);
    st.insert(Node(l, r, status));
}
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    st.insert(Node(1, n, 1));
    tot = n;
    for (int i = 1; i <= q; i++)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        edit(l, r, k - 1);
        printf("%d\n", tot);
    }
    return 0;
}