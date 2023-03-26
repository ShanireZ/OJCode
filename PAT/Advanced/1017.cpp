#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Cus
{
    int arr, poc;
    bool operator<(const Cus &oth) const
    {
        return arr < oth.arr;
    }
};
Cus cs[10005];
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
    int n, k, cnt = 0, tot = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> t >> cs[i].poc;
        cs[i].arr = (t[7] - '0') + (t[6] - '0') * 10 +
                    ((t[4] - '0') + (t[3] - '0') * 10) * 60 +
                    ((t[1] - '0') + (t[0] - '0') * 10) * 3600;
        cnt += (cs[i].arr < 61200);
    }
    for (int i = 1; i <= k; i++)
    {
        q.push(28800);
    }
    sort(cs + 1, cs + 1 + n);
    for (int i = 1; i <= cnt; i++)
    {
        int now = q.top();
        q.pop();
        tot += max(now, cs[i].arr) - cs[i].arr, q.push(max(now, cs[i].arr) + cs[i].poc * 60);
    }
    cout << fixed << setprecision(1) << tot / 60.0 / cnt;
    return 0;
}