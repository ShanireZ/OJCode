#include <algorithm>
#include <iostream>
using namespace std;
int sta[10][10], pwd[10], n, ans;
bool check()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int ok = 1;
        for (int j = 1; j <= 5; j++)
        {
            if (pwd[j] != sta[i][j])
            {
                ok = 0;
                break;
            }
        }
        res += ok;
    }
    return res;
}
void dfs(int step)
{
    if (step > 5)
    {
        int cnt = 0;
        for (int i = 1; i <= 5; i++)
        {
            for (int ex = 1; ex < 10; ex++)
            {
                pwd[i] = (pwd[i] + 1) % 10;
                cnt += check(); // 1个圈
                if (i < 5)
                {
                    pwd[i + 1] = (pwd[i + 1] + ex) % 10;
                    cnt += check(); // 2个圈
                    pwd[i + 1] = (pwd[i + 1] - ex + 10) % 10;
                }
            }
            pwd[i] = (pwd[i] + 1) % 10;
        }
        ans += (cnt == n);
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        pwd[step] = i;
        dfs(step + 1);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> sta[i][j];
        }
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}