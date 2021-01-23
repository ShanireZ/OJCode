#include <cstdio>
#include <set>
using namespace std;
int read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    int t = 1, n = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}
struct Node
{
    int l, r, v;
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
set<Node>::iterator split(int pos)
{
    set<Node>::iterator it = st.lower_bound(Node(pos, 0, 0));
    if (it->l == pos)
    {
        return it;
    }
    it--;
    int l = it->l, r = it->r, v = it->v;
    st.erase(it);
    st.insert(Node(l, pos - 1, v));
    return st.insert(Node(pos, r, v)).first;
}
void edit(int l, int r, int k)
{
    set<Node>::iterator itr = split(r + 1);
    set<Node>::iterator itl = split(l);
    st.erase(itl, itr);
    st.insert(Node(l, r, k));
}
int status[1005], ans;
int main()
{
    int n = read(), m = read();
    st.insert(Node(1, n, 0));
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        edit(l, r, i);
    }
    for (set<Node>::iterator it = st.begin(); it != st.end(); it++)
    {
        int id = it->v;
        if (id == 0)
        {
            continue;
        }
        if (status[id] == 0)
        {
            status[id] = 1;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}