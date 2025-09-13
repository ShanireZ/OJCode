#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> l[100005];
int ok[100005], n, m, ans;
void f(int x)
{
    ok[x] = 1;
    for (int i = 0; i < l[x].size(); i++)
    {
        int y = l[x][i];
        if (ok[y] == 0)
        {
            f(y);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int p, q;
        cin >> p >> q;
        l[p].push_back(q), l[q].push_back(p);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ok[i] == 0)
        {
            f(i);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}