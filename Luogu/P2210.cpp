#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;
mt19937 gen(time(0));
int n, p[15], f[15][5];
int SA()
{
    int res = 1e9;
    double T = 10000;
    while (T >= 1e-15)
    {
        int x = gen() % n + 1, y = gen() % n + 1;
        swap(p[x], p[y]);
        int now = 0;
        for (int i = 1; i <= n; i++)
        {
            now += abs(p[f[i][1]] - p[i]) + abs(p[f[i][2]] - p[i]) + abs(p[f[i][3]] - p[i]);
        }
        now /= 2;
        if (now < res || exp((res - now) / T) * 100 > gen() % 100)
        {
            res = now;
        }
        else
        {
            swap(p[x], p[y]);
        }
        T = 0.97 * T;
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i][1] >> f[i][2] >> f[i][3];
        p[i] = i;
    }
    int ans = 1e9;
    while (double(clock()) / CLOCKS_PER_SEC <= 0.9)
    {
        shuffle(p + 1, p + 1 + n, gen);
        ans = min(ans, SA());
    }
    cout << ans << endl;
    return 0;
}