#include <iostream>
#include <string>
using namespace std;
long long base = 377, mod = 999983, h[100005];
int flag[1000005], cnt[1000005], ans1, ans2 = 100005;
string str;
long long make_hash(string s)
{
    long long hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * base + s[i]) % mod;
    }
    return hash;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        long long hash = make_hash(str);
        flag[hash] = 1;
    }
    int m, l = 1;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> str;
        long long hash = make_hash(str);
        h[i] = hash;
        if (flag[hash])
        {
            cnt[hash]++;
        }
        if (cnt[hash] == 1)
        {
            ans1++, ans2 = i - l + 1;
        }
        while (l <= i)
        {
            if (cnt[h[l]] == 1)
            {
                break;
            }
            else if (cnt[h[l]] > 1)
            {
                cnt[h[l]]--;
            }
            l++;
        }
        ans2 = min(ans2, i - l + 1);
    }
    cout << ans1 << endl
         << ans2 << endl;
    return 0;
}