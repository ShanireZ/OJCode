#include <iostream>
#include <set>
using namespace std;
struct Node
{
    int l, r;
    bool operator<(const Node oth) const
    {
        return r < oth.l;
    }
    // 如果r比其他Node.l小，那么就算当前Node小；反之则大；其他情况则算相等
};
set<Node> s;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'A')
        {
            int l, r;
            cin >> l >> r;
            int st = s.size();
            auto itl = s.lower_bound(Node{l, r});
            auto itr = s.upper_bound(Node{l, r});
            s.erase(itl, itr);
            cout << st - s.size() << '\n';
            s.insert(Node{l, r});
        }
        else
        {
            cout << s.size() << '\n';
        }
    }
    return 0;
}