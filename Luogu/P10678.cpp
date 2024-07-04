#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int d, id;
    bool operator<(const Node &a) const
    {
        return d > a.d;
    }
};
Node ns[200005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> ns[i].d;
            ns[i].id = i;
        }
        sort(ns + 1, ns + n + 1);
        int p = 2;
        for (int i = 1; i <= n; i++)
        {
            if (ns[i].d == 0)
            {
                continue;
            }
            for (int t = 1; t <= ns[i].d; t++)
            {
                cout << ns[i].id << " " << ns[p].id << '\n';
                ns[p].d--;
                p++;
            }
        }
    }
    return 0;
}