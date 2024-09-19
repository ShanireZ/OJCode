#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
multiset<int> s;
int f[105][105];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * n; i++)
    {
        s.emplace(0);
    }
    for (int i = 1; i <= m; i++)
    {
        int opt, a, b, c;
        cin >> opt >> a >> b >> c;
        if (opt == 2)
        {
            opt = -1;
        }
        s.erase(s.lower_bound(f[a][b]));
        f[a][b] += opt * c;
        s.emplace(f[a][b]);
        cout << *(--s.end()) << endl;
    }
    return 0;
}