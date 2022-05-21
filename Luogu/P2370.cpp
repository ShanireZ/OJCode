#include <algorithm>
#include <iostream>
using namespace std;
int dp[1005];
struct Node
{
    int w, v;
    bool operator<(const Node oth) const
    {
        return w < oth.w;
    }
};
Node ns[1005];
int main()
{
    int n, p, s;
    cin >> n >> p >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].w >> ns[i].v;
    }
    sort(ns + 1, ns + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= ns[i].w; j--)
        {
            dp[j] = max(dp[j], dp[j - ns[i].w] + ns[i].v);
        }
        if (dp[s] >= p)
        {
            cout << ns[i].w << endl;
            return 0;
        }
    }
    cout << "No Solution!" << endl;
    return 0;
}