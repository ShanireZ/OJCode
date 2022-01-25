#include <iostream>
#include <cmath>
using namespace std;
int n, k, ans, nums[25];
void dfs(int cnt, int tot, int last)
{
    if (cnt == k)
    {
        for (int i = 2; i <= sqrt(tot); i++)
        {
            if (tot % i == 0)
            {
                return;
            }
        }
        ans++;
        return;
    }
    for (int i = last + 1; i <= n; i++)
    {
        dfs(cnt + 1, tot + nums[i], i);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(1, nums[i], i);
    }
    cout << ans << endl;
    return 0;
}