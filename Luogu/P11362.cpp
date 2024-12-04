#include <algorithm>
#include <iostream>
using namespace std;
#define MOD 1000000007
struct Node
{
    int id, val;
    bool operator<(const Node &oth) const
    {
        return id < oth.id;
    }
    bool operator==(const Node &oth) const
    {
        return (id == oth.id && val == oth.val);
    }
};
Node ns[100005];
long long pwm(long long a, int b)
{
    long long res = 1;
    while (b)
    {
        if (b % 2)
        {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, v, trig = 0;
        cin >> n >> m >> v;
        for (int i = 1; i <= m; i++)
        {
            int c, d;
            cin >> c >> d;
            ns[i] = Node{c, d};
        }
        sort(ns + 1, ns + 1 + m);
        m = unique(ns + 1, ns + 1 + m) - ns - 1;
        for (int i = 1; i < m && trig == 0; i++)
        {
            trig = (ns[i].id == ns[i + 1].id);
        }
        if (trig)
        {
            cout << 0 << endl;
            continue;
        }
        long long ans = pwm(v, (ns[1].id - 1) * 2) * pwm(v, (n - ns[m].id) * 2) % MOD;
        for (int i = 2; i <= m; i++)
        {
            int len = ns[i].id - ns[i - 1].id;
            ans = ans * (pwm(v, len * 2) - pwm(v, len - 1) * (v - 1) % MOD + MOD) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}