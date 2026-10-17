#include <iostream>
using namespace std;
int all[5][100];
void next(int &x)
{
    (x == 3) ? x = 1 : x += 1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 3; i++)
    {
        all[i][0] = n;
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            all[i][x]++;
        }
    }
    int pt = 0, cnt = 1;  // 前一次牌的分數和個數
    int now = 1, pre = 3; // 當前出牌者 之前出牌者
    int pass = 0;         // 空過了幾個人
    while (true)
    {
        int trig = 0;                            // 當前出牌者是否出牌
        for (int t = cnt; t <= all[now][0]; t++) // 出幾張牌
        {
            for (int i = 1; i <= m; i++) // 出什麼牌
            {
                // 牌的數量必須夠 && (如果僅出cnt張那麼分數必須大 || 牌數更多不看分數)
                if (all[now][i] >= t && (t == cnt && i > pt || t != cnt))
                {
                    trig = 1, pass = 0;
                    all[now][i] -= t;
                    all[now][0] -= t;
                    if (all[now][0] == 0) // winner
                    {
                        cout << now;
                        return 0;
                    }
                    pt = i, cnt = t, pre = now;
                    next(now);
                    break;
                }
            }
            if (trig)
            {
                break;
            }
        }
        if (trig == 0)
        {
            next(now);
            pass++;
            if (pass == 2) // 此輪結束
            {
                pt = 0, cnt = 1, pass = 0;
            }
        }
    }
    return 0;
}