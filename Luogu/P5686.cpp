#include <iostream>
using namespace std;
#define MX 500005
#define MOD 1000000007
long long qa[MX], qb[MX], qqab[MX], qqa[MX], qqb[MX];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> qa[i];
        qa[i] = (qa[i] + qa[i - 1]) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> qb[i];
        qb[i] = (qb[i] + qb[i - 1]) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        qqa[i] = (qqa[i - 1] + qa[i]) % MOD;
        qqb[i] = (qqb[i - 1] + qb[i]) % MOD;
        qqab[i] = (qqab[i - 1] + (qa[i] * qb[i] % MOD)) % MOD;
    }
    long long ans = ((qqab[n] * (n + 1) % MOD) + MOD - (qqa[n] * qqb[n] % MOD)) % MOD;
    cout << ans << endl;
    return 0;
}