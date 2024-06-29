#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
int f[55][55], p[55], n, a, b, ans = 1;
mt19937 rnd(time(0));
int main()
{
    for (int i = 1; i <= 50; i++)
    {
        p[i] = i;
    }
    cin >> n;
    while (cin >> a >> b)
    {
        f[a][b] = f[b][a] = 1;
    }
    for (int t = 1; t <= 100000; t++)
    {
        shuffle(p + 1, p + 1 + n, rnd);
        vector<int> sp;
        sp.emplace_back(p[1]);
        for (int i = 2; i <= n; i++)
        {
            int ok = 1;
            for (int j : sp)
            {
                if (f[j][p[i]] == 0)
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                sp.emplace_back(p[i]);
            }
        }
        ans = max(ans, (int)sp.size());
    }
    cout << ans << endl;
    return 0;
}
// TAG: 随机化