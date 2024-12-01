#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string s1, s2, t1, t2;
struct Node
{
    int c0, c1;
};
vector<Node> k1, k2;
int check(int st, int ed)
{
    k1.clear(), k2.clear();
    int pos = st - 1, res = 0, sta1 = 0, sta2 = 0, c1[2] = {0, 0}, c2[2] = {0, 0};
    while (++pos <= ed)
    {
        if (t1[pos] != sta1)
        {
            k1.push_back({c1[0], c1[1]});
            c1[0] = c1[1] = 0, sta1 = t1[pos];
        }
        if (t2[pos] != sta2)
        {
            k2.push_back({c2[0], c2[1]});
            c2[0] = c2[1] = 0, sta2 = t2[pos];
        }
        c1[s1[pos] - '0']++, c2[s2[pos] - '0']++;
    }
    k1.push_back({c1[0], c1[1]}), k2.push_back({c2[0], c2[1]});
    while (k1.size() && k2.size())
    {
        int same0 = min(k1.back().c0, k2.back().c0), same1 = min(k1.back().c1, k2.back().c1);
        int ex = min(k1.back().c0 + k1.back().c1, k2.back().c0 + k2.back().c1) - same0 - same1;
        k1.back().c0 -= same0, k1.back().c1 -= same1;
        k1.back().c0 ? k1.back().c0 -= ex : k1.back().c1 -= ex;
        if (k1.back().c0 + k1.back().c1 == 0)
        {
            k1.pop_back();
        }
        k2.back().c0 -= same0, k2.back().c1 -= same1;
        k2.back().c0 ? k2.back().c0 -= ex : k2.back().c1 -= ex;
        if (k2.back().c0 + k2.back().c1 == 0)
        {
            k2.pop_back();
        }
        res += same0 + same1;
    }
    return res;
}
int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n >> s1 >> s2 >> t1 >> t2;
        int ans = 0, pre = 0;
        for (int i = 0; i < n; i++)
        {
            if (t1[i] == '0' && t2[i] == '0')
            {
                ans += check(pre, i - 1) + (s1[i] == s2[i]);
                pre = i + 1;
            }
        }
        ans += check(pre, n - 1);
        cout << ans << endl;
    }
    return 0;
}