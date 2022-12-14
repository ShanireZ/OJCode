#include <iostream>
#include <set>
using namespace std;
set<int> s;
int n, a, k, ans[10];
void dfs(int now, int step, int lim)
{
    if (step == lim)
    {
        int num = 0;
        for (int i = 1; i <= n; i++)
        {
            num = num * 10 + ans[i];
        }
        s.insert(num);
        return;
    }
    for (int i = now + 1; i <= n; i++)
    {
        ans[i] = (ans[i] - 1 + 10) % 10, dfs(i, step + 1, lim); // -1
        ans[i] = (ans[i] + 2) % 10, dfs(i, step + 1, lim);      // +1
        ans[i] = (ans[i] - 1 + 10) % 10;                        // 回溯初始状态
    }
}
int main()
{
    scanf("%d %d %d", &n, &a, &k);
    for (int i = n; i >= 1; i--)
    {
        ans[i] = a % 10, a /= 10;
    }
    for (int t = 0; t <= k; t++)
    {
        dfs(0, 0, t);
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        printf("%d\n", *it);
    }
    return 0;
}