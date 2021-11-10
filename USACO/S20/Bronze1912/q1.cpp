#include <iostream>
#include <fstream>
using namespace std;
int rnk[25][15];
int main()
{
    // freopen("gymnastics.in", "r", stdin);
    // freopen("gymnastics.out", "w", stdout);
    // ios::sync_with_stdio(false);
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp;
            cin >> tmp;
            rnk[tmp][i] = j; //!奶牛tmp在第i轮的排名为j
        }
    }
    int tot = n * n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int r = 1; r <= k; r++)
            {
                if (rnk[i][r] >= rnk[j][r])
                {
                    tot--;
                    break;
                }
            }
        }
    }
    cout << tot;
    return 0;
}