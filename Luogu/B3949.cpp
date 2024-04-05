#include <algorithm>
#include <iostream>
using namespace std;
int n, k, ans;
void dfs(int now, int tot)
{
    for (int i = 0; i <= 9; i++)
    {
        if (now == 1 && i == 0)
        {
            continue;
        }
        if (tot + i > k)
        {
            return;
        }
        ans++;
        if (now < n)
        {
            dfs(now + 1, tot + i);
        }
    }
}
int main()
{
    cin >> n >> k;
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}