#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int e[5005];
map<int, int> mp;
int main()
{
    int n, m, c0 = 0, c1 = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> e[i];
        mp[e[i]] = -1;
    }
    for (int i = 1; i <= m; i++)
    {
        int p, s;
        cin >> p >> s;
        mp[p] = s;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[e[i]] == -1)
        {
            c0++;
        }
        if (mp[e[i]] < 60)
        {
            c1++;
        }
    }
    cout << c0 << "\n"
         << c1 << "\n";
    return 0;
}