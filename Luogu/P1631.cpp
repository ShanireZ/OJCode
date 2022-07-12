#include <iostream>
#include <queue>
using namespace std;
struct Tot
{
    int v, aid, bid;
    bool operator<(const Tot nt) const
    {
        return v > nt.v;
    }
};
priority_queue<Tot> q;
int a[100005], b[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        q.push(Tot{a[1] + b[i], 1, i});
    }
    for (int i = 1; i <= n; i++)
    {
        cout << q.top().v << ' ';
        q.push(Tot{a[q.top().aid + 1] + b[q.top().bid], q.top().aid + 1, q.top().bid});
        q.pop();
    }
    return 0;
}