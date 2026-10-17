#include <cstring>
#include <iostream>
#include <vector>
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
        for (int x = 0; tot != m && x < 100; x++) // 如果成功消除，每輪至少能消一個
        {
            for (int i = 0; i < n; i++) // 遍歷每一位
            {
                vector<int> cnt[2][2];       // cnt[答案][字元]
                for (int j = 1; j <= m; j++) // 遍歷所有字串
                {
                    if (ok[j] == 0)
                    {
                        cnt[ans[j]][str[j][i] - '0'].push_back(j); // 統計狀態
                    }
                }
                for (int a = 0; a <= 1; a++)
                {
                    for (int c = 0; c <= 1; c++)
                    {
                        if (cnt[a][c].size() == 0) // 答案為a的字串第i位沒有c-->字串第i位為c答案為!a
                        {
                            for (int i = 0; i < cnt[!a][c].size(); i++)
                            {
                                int id = cnt[!a][c][i];
                                ok[id] = 1, tot++;
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