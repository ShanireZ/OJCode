#include <cstring>
#include <iostream>
#include <set>
using namespace std;
int ans[105], ok[105];
string str[105];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        memset(ok, 0, sizeof(ok));
        int n, m, tot = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> str[i] >> ans[i];
        }
        for (int x = 0; tot != m && x < n; x++) // 如果成功消除，每轮至少能消一个
        {
            for (int i = 0; i < n; i++) // 遍历每一位
            {
                set<int> cnt[2][2];          // cnt[答案][字符]
                for (int j = 1; j <= m; j++) // 遍历所有字符串
                {
                    if (ok[j] == 0)
                    {
                        cnt[ans[j]][str[j][i] - '0'].insert(j); // 统计状态
                    }
                }
                for (int a = 0; a <= 1; a++)
                {
                    for (int c = 0; c <= 1; c++)
                    {
                        if (cnt[a][c].size() == 0) // 答案为a的字符串第i位没有c-->字符串第i位为c答案为!a
                        {
                            for (auto it = cnt[!a][c].begin(); it != cnt[!a][c].end(); it++)
                            {
                                ok[*it] = 1, tot++;
                            }
                        }
                    }
                }
            }
        }
        cout << ((tot == m) ? "OK\n" : "LIE\n");
    }
    return 0;
}