#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;
int a[35], n;
mt19937 gen(time(0));
long long make()
{
    long long res = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        res = res + a[i];
    }
    for (int i = n / 2 + 1; i <= n; i++)
    {
        res = res - a[i];
    }
    return res < 0 ? -res : res;
}
long long SA()
{
    long long res = make();
    double T = 10000;
    while (T >= 1e-15)
    {
        int x = gen() % n + 1, y = gen() % n + 1;
        swap(a[x], a[y]);
        long long now = make();
        if (now < res || exp((res - now) / T) * 100 > gen() % 100)
        {
            res = now;
        }
        else
        {
            swap(a[x], a[y]);
        }
        T = T * 0.95;
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    int lmt = 900 / T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        long long ans = 1e18, t = 1000;
        while (t--)
        {
            ans = min(ans, SA());
        }
        cout << ans << endl;
    }
    return 0;
}