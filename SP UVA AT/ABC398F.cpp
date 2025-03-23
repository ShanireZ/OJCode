#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct Node
{
    long long hs1, hs2;
    bool operator<(const Node &oth) const
    {
        return (hs1 == oth.hs1 ? hs2 < oth.hs2 : hs1 < oth.hs1);
    }
};
string s;
map<Node, bool> mp;
long long now1, now2, b1 = 233, b2 = 311, m1 = 1000000000039ll, m2 = 1000000000061ll, pw1[500005], pw2[500005];
int main()
{
    cin >> s;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < (int)s.size(); i++)
    {
        pw1[i] = pw1[i - 1] * b1 % m1;
        pw2[i] = pw2[i - 1] * b2 % m2;
    }
    for (int i = (int)s.size() - 1, p = 0; i >= 0; i--, p++)
    {
        now1 = (now1 + pw1[p] * s[i] % m1) % m1;
        now2 = (now2 + pw2[p] * s[i] % m2) % m2;
        mp[Node{now1, now2}] = 1;
    }
    now1 = now2 = 0;
    int ans = s.size();
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        now1 = (now1 * b1 + s[i]) % m1;
        now2 = (now2 * b2 + s[i]) % m2;
        if (mp[Node{now1, now2}])
        {
            ans = min(ans, i);
        }
    }
    cout << s;
    for (int i = ans - 1; i >= 0; i--)
    {
        cout << s[i];
    }
    return 0;
}