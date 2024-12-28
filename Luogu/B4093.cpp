#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;
mt19937 rnd(time(0));
int n, s, ans = 100, a[20], g[20], w[20];
long long m;
string str;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    getline(cin, str);
    for (int i = 1; i <= s; i++)
    {
        getline(cin, str);
        int id = 0;
        for (char ch : str)
        {
            isdigit(ch) ? (id = id * 10 + ch - '0') : (g[id] = i, id = 0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i] == 0)
        {
            g[i] = ++s;
        }
        w[g[i]] += a[i];
    }
    while ((double)clock() / CLOCKS_PER_SEC <= 0.9)
    {
        shuffle(w + 1, w + 1 + s, rnd);
        int cnt = 1, tot = 0;
        for (int i = 1; i <= s; i++)
        {
            tot + w[i] <= m ? (tot += w[i]) : (tot = w[i], cnt += 1);
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}