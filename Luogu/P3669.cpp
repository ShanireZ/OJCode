#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    long long c, x;
    bool operator<(const Node &oth) const
    {
        return x < oth.x;
    }
};
Node ns[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].c >> ns[i].x;
    }
    sort(ns + 1, ns + n + 1);
    long long ans = 0;
    for (int i = 1, j = n; i < j;)
    {
        if (ns[i].c > ns[j].c)
        {
            ns[i].c -= ns[j].c;
            ans = max(ans, ns[i].x + ns[j].x);
            j--;
        }
        else if (ns[i].c < ns[j].c)
        {
            ns[j].c -= ns[i].c;
            ans = max(ans, ns[i].x + ns[j].x);
            i++;
        }
        else
        {
            ans = max(ans, ns[i].x + ns[j].x);
            i++, j--;
        }
    }
    cout << ans << endl;
    return 0;
}
// TAG: 贪心