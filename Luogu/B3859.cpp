#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s, t, ns1, ns2;
int x[100005], y[100005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> s >> t;
        int szt = t.size(), szs = s.size();
        for (int i = 1; i < min(szs, szt); i++)
        {
            ns1 = s.substr(0, i), ns2 = s.substr(szs - i, i);
            int ok1 = 1, ok2 = 1;
            for (int p = 0; p < i && (ok1 || ok2); p++)
            {
                if (ns1[p] != t[szt - i + p])
                {
                    ok1 = 0;
                }
                if (ns2[p] != t[p])
                {
                    ok2 = 0;
                }
            }
            x[i] = ok1, y[i] = ok2;
        }
        int ans = 0;
        for (int i = 1; i < min(szs, szt) && szt - i <= szs; i++)
        {
            if (x[i] + y[szt - i] == 2)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}