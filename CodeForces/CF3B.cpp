#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int p, ok, id;
    bool operator<(const Node oth) const
    {
        return p > oth.p;
    }
};
Node s1[100005], s2[100005];
int n, v, pos1, pos2;
int main()
{
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
        int t, p;
        cin >> t >> p;
        if (t == 1)
        {
            s1[++pos1].id = i;
            s1[pos1].p = p;
        }
        else
        {
            s2[++pos2].id = i;
            s2[pos2].p = p;
        }
    }
    sort(s1 + 1, s1 + 1 + pos1), sort(s2 + 1, s2 + 1 + pos2);
    long long ans = 0;
    int p2 = min(v / 2, pos2);
    for (int i = 1; i <= p2; i++)
    {
        ans += s2[i].p, s2[i].ok = 1;
    }
    v -= p2 * 2;
    int p1 = min(v, pos1);
    for (int i = 1; i <= p1; i++)
    {
        ans += s1[i].p, s1[i].ok = 1;
    }
    p1++;
    while (p1 <= pos1 && p2 >= 1)
    {
        if (s1[p1].p + s1[p1 + 1].p > s2[p2].p)
        {
            s2[p2].ok = 0, s1[p1].ok = s1[p1 + 1].ok = 1;
            ans += s1[p1].p + s1[p1 + 1].p - s2[p2].p;
            p2--, p1 += 2;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= pos1; i++)
    {
        if (s1[i].ok)
        {
            cout << s1[i].id << " ";
        }
    }
    for (int i = 1; i <= pos2; i++)
    {
        if (s2[i].ok)
        {
            cout << s2[i].id << " ";
        }
    }
    return 0;
}