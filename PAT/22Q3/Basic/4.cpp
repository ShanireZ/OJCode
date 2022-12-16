#include <iostream>
using namespace std;
int cnt[3000005];
int main() // 有可能跳到气球区间外
{
    int n, h, ex = 2000000;
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        cnt[ex + p] += 1;
    }
    for (int i = 1; i <= 3000000; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    int maxc = cnt[h], pos = 0;
    for (int i = 1; i <= 3000000 - h; i++)
    {
        int c = cnt[i + h] - cnt[i - 1];
        if (c > maxc)
        {
            maxc = c, pos = i;
        }
    }
    cout << pos - ex << " " << maxc << endl;
    return 0;
}