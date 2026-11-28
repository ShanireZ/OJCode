#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int v, x, y;
    bool operator<(const Node &oth) const
    {
        if (v == oth.v)
        {
            if (y == oth.y)
            {
                return x > oth.x;
            }
            return y < oth.y;
        }
        return v < oth.v;
    }
};
Node ns[40005];
int n, m, pos;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch != '.')
            {
                ns[++pos] = Node{ch - 'A', i, j};
            }
        }
    }
    sort(ns + 1, ns + pos + 1);
    for (int i = 1; i <= pos; i++)
    {
        cout << ns[i].x << "," << ns[i].y << endl;
    }
    return 0;
}