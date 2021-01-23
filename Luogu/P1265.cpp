#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
struct Node
{
    int x, y, g;
};
Node ns[5005];
double len[5005];
double dis(int a, int b)
{
    return pow(pow(ns[a].x - ns[b].x, 2) + pow(ns[a].y - ns[b].y, 2), 0.5);
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
        len[i] = 3000000;
    }
    int cnt = 1, last = 1;
    double ans = 0;
    ns[1].g = 1;
    while (cnt < n)
    {
        int min_to = 0;
        double min_len = 3000000;
        for (int i = 1; i <= n; i++)
        {
            if (ns[i].g == 0)
            {
                double tmp = dis(last, i);
                len[i] = min(len[i], tmp);
                if (len[i] < min_len)
                {
                    min_len = len[i];
                    min_to = i;
                }
            }
        }
        last = min_to;
        ns[last].g = 1;
        ans += min_len;
        cnt++;
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}