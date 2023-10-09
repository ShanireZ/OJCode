#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define MX 35
long long p[MX], qz[MX], cnt[MX], nums[MX];
int main()
{
    p[0] = qz[0] = 1;
    for (int i = 1; i <= 30; i++)
    {
        p[i] = p[i - 1] * 2;
        qz[i] = qz[i - 1] + p[i];
    }
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        if (n == 1)
        {
            if (m == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
            continue;
        }
        // last最下层节点数 x次下层的深度,深度从0开始计算
        int x = log2(n - 1);
        long long last = (n - p[x]) * 2;
        if (last + qz[x] <= m)
        {
            cout << -1 << endl;
            continue;
        }
        else if (m == 0)
        {
            memset(cnt, 0, sizeof(cnt));
            long long tot = (qz[x] + 1) * qz[x] / 2 + (p[x] * 4 + 1) * last / 2;
            long long tot2 = (qz[x] + 1) * qz[x] / 2;
            long long now = n - p[x] - 1, pos = 0; // 计算 0至last/2-1 二进制反转之和
            while (now)
            {
                nums[pos++] = now % 2, now /= 2;
            }
            for (int i = 0; i < pos; i++)
            {
                if (nums[i]) // 可差分优化
                {
                    cnt[i] += now + 1;
                    for (int j = i - 1; j >= 0; j--)
                    {
                        cnt[j] += p[i - 1];
                    }
                    now += p[i];
                }
            }
            for (int i = x - 1, j = 0; i >= 0; i--, j++)
            {
                tot += cnt[j] * p[i] * 4;
            }
            cout << max(tot / (x + 2), tot2 / (x + 1)) << endl;
            continue;
        }
        while (last < m)
        {
            last += p[x--];
        }
        cout << (qz[x] + 1) * qz[x] / 2 / (x + 1) << endl;
    }
    return 0;
}
// https://oeis.org/A030109