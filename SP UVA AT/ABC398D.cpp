#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct Node
{
    int x, y;
    bool operator<(const Node &oth) const
    {
        if (x == oth.x)
        {
            return y < oth.y;
        }
        return x < oth.x;
    }
};
map<Node, int> mp;
int n, r, c, ex, ey;
string s;
int main()
{
    cin >> n >> r >> c >> s;
    s.insert(0, "X");
    for (int i = 1; i <= n; i++)
    {
        mp[Node{ex, ey}] = 1;
        if (s[i] == 'N' || s[i] == 'S')
        {
            ex += (s[i] == 'S' ? 1 : -1);
        }
        else
        {
            ey += (s[i] == 'E' ? 1 : -1);
        }
        cout << (mp[Node{ex - r, ey - c}] ? 1 : 0);
    }
    return 0;
}