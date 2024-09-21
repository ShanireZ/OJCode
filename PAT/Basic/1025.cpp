#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int n, k, pos, itp[100005], a[100005];
string hd;
map<string, int> ids;
struct Node
{
    string adr, v, nxt;
};
Node ns[100005];
int main()
{
    cin >> hd >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].adr >> ns[i].v >> ns[i].nxt;
        if (ids[ns[i].adr] == 0)
        {
            ids[ns[i].adr] = ++pos;
        }
        if (ids[ns[i].nxt] == 0)
        {
            ids[ns[i].nxt] = ++pos;
        }
        itp[ids[ns[i].adr]] = i;
    }
    int p = itp[ids[hd]], trig = 0;
    while (p)
    {
        int i = 0;
        while (i < k && p)
        {
            a[++i] = p;
            p = itp[ids[ns[p].nxt]];
        }
        if (i == k)
        {
            reverse(a + 1, a + 1 + k);
        }
        for (int j = 1; j <= i; j++, trig = 1)
        {
            if (trig)
            {
                cout << ns[a[j]].adr << "\n";
            }
            cout << ns[a[j]].adr << " " << ns[a[j]].v << " ";
        }
    }
    cout << "-1\n";
    return 0;
}