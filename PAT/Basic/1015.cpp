#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
struct Node
{
    int id, tot, d, c;
    bool operator<(const Node oth) const
    {
        if (tot == oth.tot)
        {
            return (d == oth.d) ? (id < oth.id) : (d > oth.d);
        }
        return tot > oth.tot;
    }
};
vector<Node> ns[5];
int main()
{
    int n, l, h, cnt = 0;
    cin >> n >> l >> h;
    for (int i = 1; i <= n; i++)
    {
        int id, d, c;
        cin >> id >> d >> c;
        Node now = Node{id, d + c, d, c};
        if (d >= l && c >= l)
        {
            if (d >= h)
            {
                c >= h ? ns[1].push_back(now) : ns[2].push_back(now);
            }
            else
            {
                d >= c ? ns[3].push_back(now) : ns[4].push_back(now);
            }
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= 4; i++)
    {
        sort(ns[i].begin(), ns[i].end());
        for (int j = 0; j < (int)ns[i].size(); j++)
        {
            cout << ns[i][j].id << " " << ns[i][j].d << " " << ns[i][j].c << "\n";
        }
    }
    return 0;
}