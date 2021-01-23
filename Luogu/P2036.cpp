#include <iostream>
#include <algorithm>
using namespace std;
int s[15], b[15];
int ans, n;
void dfs(int x, int suan, int tian)
{
    if (x > n)
    {
        if (suan != 1 || tian != 0)
        {
            ans = min(abs(suan - tian), ans);
        }
        return;
    }
    //选择了x
    dfs(x + 1, suan * s[x], tian + b[x]);
    //没选择x
    dfs(x + 1, suan, tian);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> b[i];
    }
    ans = 0x3f3f3f3f;
    dfs(1, 1, 0);
    cout << ans;
    return 0;
}