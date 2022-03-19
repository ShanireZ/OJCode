#include <iostream>
#include <string>
using namespace std;
long long base = 233, mod = 299999977;
string a, b;
long long qa[100], qb[100], ha[100], hb[100], p[100];
int main()
{
    cin >> a >> b;
    int len = min(a.size(), b.size());
    long long hasha = 0, hashb = 0;
    for (int i = 0; i < len; i++)
    {
        hasha = (hasha * base + a[i]) % mod;
        qa[i + 1] = hasha;
        hashb = (hashb * base + b[i]) % mod;
        qb[i + 1] = hashb;
    }
    p[0] = 1;
    for (int i = 1; i <= 80; i++)
    {
        p[i] = (p[i - 1] * base) % mod;
    }
    hasha = hashb = 0;
    for (int i = 0; i < len; i++)
    {
        hasha = (hasha + p[i] * a[a.size() - 1 - i]) % mod;
        ha[i + 1] = hasha;
        hashb = (hashb + p[i] * b[b.size() - 1 - i]) % mod;
        hb[i + 1] = hashb;
    }
    for (int i = len; i >= 1; i--)
    {
        if (qb[i] == ha[i] || qa[i] == hb[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}