#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int xd[10][10] = {{0, 2, 6, 11, 15, 20, 22},
                  {1, 3, 8, 12, 17, 21, 23},
                  {10, 9, 8, 7, 6, 5, 4},
                  {19, 18, 17, 16, 15, 14, 13},
                  {23, 21, 17, 12, 8, 3, 1},
                  {22, 20, 15, 11, 6, 2, 0},
                  {13, 14, 15, 16, 17, 18, 19},
                  {4, 5, 6, 7, 8, 9, 10}}; // ABCDEFGH
int p[10] = {6, 7, 8, 11, 12, 15, 16, 17}, anti[10] = {5, 4, 7, 6, 1, 0, 3, 2}, nums[30], n;
string bz;
bool dfs(int lim, int step, int pre, int ns[30])
{
    int cnt[5] = {0}, same = 0;
    for (int i = 0; i < 8; i++)
    {
        int x = ns[p[i]];
        cnt[x]++;
        if (cnt[x] > cnt[same])
        {
            same = x;
        }
    }
    if (cnt[same] == 8)
    {
        n = same;
        return true;
    }
    if (8 - cnt[same] + step > lim)
    {
        return false;
    }
    for (int i = 0; i < 8; i++)
    {
        if (pre == anti[i])
        {
            continue;
        }
        int nxt[30] = {0};
        for (int j = 0; j < 24; j++)
        {
            nxt[j] = ns[j];
        }
        for (int j = 0; j < 6; j++)
        {
            nxt[xd[i][j]] = nxt[xd[i][j + 1]];
        }
        nxt[xd[i][6]] = ns[xd[i][0]];
        if (dfs(lim, step + 1, i, nxt))
        {
            bz = char(i + 'A') + bz;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> nums[0];
    while (nums[0] != 0)
    {
        for (int i = 1; i < 24; i++)
        {
            cin >> nums[i];
        }
        n = 0, bz.erase();
        for (int i = 0; i < 30; i++)
        {
            if (dfs(i, 0, -1, nums))
            {
                if (i == 0)
                {
                    cout << "No moves needed" << endl;
                }
                else
                {
                    cout << bz << endl;
                }
                cout << n << endl; // 无论什么情况都要输出第二行
                break;
            }
        }
        cin >> nums[0];
    }
    return 0;
}