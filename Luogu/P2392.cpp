#include <iostream>
#include <algorithm>
using namespace std;
int t[25], s[5];
int ans, tot;
void dfs(int type, int x, int t1, int t2)
{
    if (x > s[type])
    {
        ans = min(max(t1, t2), ans);
        return;
    }
    dfs(type, x + 1, t1 + t[x], t2);
    dfs(type, x + 1, t1, t2 + t[x]);
}
int main()
{
    cin >> s[1] >> s[2] >> s[3] >> s[4];
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= s[i]; j++)
        {
            cin >> t[j];
        }
        ans = 10000;
        dfs(i, 1, 0, 0);
        tot += ans;
    }
    cout << tot;
    return 0;
}