#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, m;
vector<int> all;
struct Node
{
    int l, r;
    Node(int L, int R)
    {
        l = L, r = R;
    }
    bool operator<(const Node &another) const
    {
        return l < another.l;
    }
};
set<Node> s;
void destroy(int x)
{
    set<Node>::iterator it = s.lower_bound(Node(x, 0));
    if (it == s.end() || (it != s.begin() && it->l != x))
    {
        it--;
    }
    int l = it->l, r = it->r;
    s.erase(it);
    if (l != x)
    {
        s.insert(Node(l, x - 1));
    }
    if (r != x)
    {
        s.insert(Node(x + 1, r));
    }
}
void restore(int x)
{
    set<Node>::iterator it = s.lower_bound(Node(x, 0));
    int l, r = x;
    if (it != s.end() && it->l == x + 1)
    {
        r = it->r;
        s.erase(it);
        it = s.insert(Node(x, r)).first;
    }
    else
    {
        it = s.insert(Node(x, x)).first;
    }
    if (it == s.begin())
    {
        return;
    }
    set<Node>::iterator it2 = it;
    it2++, it--;
    if (it->r == x - 1)
    {
        l = it->l;
        s.erase(it, it2);
        s.insert(Node(l, r));
    }
}
int querry(int x)
{
    set<Node>::iterator it = s.lower_bound(Node(x, 0));
    if (it == s.end() || (it != s.begin() && it->l != x))
    {
        it--;
    }
    if (it->l <= x && it->r >= x)
    {
        return it->r - it->l + 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    cin >> n >> m;
    s.insert(Node(1, n));
    for (int i = 1; i <= m; i++)
    {
        char opt;
        int x;
        cin >> opt;
        if (opt == 'D')
        {
            cin >> x;
            destroy(x);
            all.push_back(x);
        }
        else if (opt == 'R')
        {
            x = all[all.size() - 1];
            all.pop_back();
            restore(x);
        }
        else
        {
            cin >> x;
            cout << querry(x) << endl;
        }
    }
    return 0;
}