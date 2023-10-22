#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int s[10][10], now[10], ans, n;
void dfs(int step)
{
    if (step > 5)
    {
        int ok = 1;
        for (int i = 1; i <= n; i++)
        {
            vector<int> change, pos;
            int same = 1;
            for (int j = 1; j <= 5; j++)
            {
                if (s[i][j] != now[j])
                {
                    int x = (s[i][j] - now[j] + 10) % 10;
                    change.push_back(x), pos.push_back(j);
                    same = 0;
                }
            }
            if (same == 1 || change.size() > 2 ||
                (change.size() == 2 && (pos[0] + 1 != pos[1] || change[0] != change[1])))
            {
                ok = 0;
                break;
            }
        }
        ans += ok;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        now[step] = i;
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
            cin >> s[i][j];
        }
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}