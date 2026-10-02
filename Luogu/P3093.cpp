#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Cow
{
    int g, d;
};
Cow cs[10005];
priority_queue<int, vector<int>, greater<int>> q;
bool cmp(Cow a, Cow b)
{
    return a.d < b.d;
}
int n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cs[i].g >> cs[i].d;
    }
    sort(cs + 1, cs + 1 + n, cmp);
    for (int i = 1, now = 1; i <= n; i++)
    {
        if (now <= cs[i].d)
        {
            q.push(cs[i].g);
            now++, ans += cs[i].g;
        }
        else if (cs[i].g > q.top())
        {
            ans -= q.top();
            q.pop();
            q.push(cs[i].g), ans += cs[i].g;
        }
    }
    cout << ans << endl;
    return 0;
}