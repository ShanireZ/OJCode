#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
int f[55][55], p[55], n, a, b;
mt19937 rnd(time(0));
bool check(int m)
{
    for (int t = 1; t <= 10000; t++)
    {
        shuffle(p + 1, p + n + 1, rnd);
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
        if (sp.size() >= m)
        {
            return true;
        }
    }
    return false;
}
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
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        check(mid) ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}