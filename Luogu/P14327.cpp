#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long H, W, a[55][55], sum[55][55];
long long count(int r1, int c1, int r2, int c2)
{
    return sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
}
int main()
{
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= H; i++) // 第一个区域前 i 行 前 j 列
    {
        for (int j = 1; j <= W; j++)
        {
            if (i == H && j == W) // 必须两个及以上区域
            {
                continue;
            }
            long long now = count(1, 1, i, j);
            long long totcol = count(1, 1, H, j), totrow = count(1, 1, i, W);
            if (totcol % now != 0 || totrow % now != 0 || sum[H][W] % now != 0)
            {
                continue;
            }
            vector<int> recx;
            recx.push_back(i);
            for (int x = i + 1, st = i + 1; x <= H; x++)
            {
                long long tot = count(st, 1, x, j);
                if (tot == now)
                {
                    st = x + 1;
                    recx.push_back(x);
                }
            }
            if (recx.size() != totcol / now || recx.back() != H)
            {
                continue;
            }
            vector<int> recy;
            recy.push_back(j);
            for (int y = j + 1, st = j + 1; y <= W; y++)
            {
                long long tot = count(1, st, i, y);
                if (tot == now)
                {
                    st = y + 1;
                    recy.push_back(y);
                }
            }
            if (recy.size() != totrow / now || recy.back() != W)
            {
                continue;
            }
            int ok = 1;
            for (int xp = 1; xp < recx.size() && ok; xp++)
            {
                for (int yp = 1; yp < recy.size() && ok; yp++)
                {
                    long long tot = count(recx[xp - 1] + 1, recy[yp - 1] + 1, recx[xp], recy[yp]);
                    if (tot != now)
                    {
                        ok = 0;
                    }
                }
            }
            ans += ok;
        }
    }
    cout << ans << endl;
    return 0;
}