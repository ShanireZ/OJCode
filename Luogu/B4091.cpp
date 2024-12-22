#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int pw[100005], sg[100005], n, tot;
queue<int> q;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pw[i];
    }
    fill(sg + 1, sg + 1 + n, 1);
    for (int i = 1; i <= n; i++)
    {
        int l = (i == 1 ? n : i - 1), r = (i == n ? 1 : i + 1);
        if (pw[i] <= pw[l] && pw[i] <= pw[r])
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        int l = (now == 1 ? n : now - 1), r = (now == n ? 1 : now + 1);
        if (pw[now] < pw[l])
        {
            q.push(l), sg[l] = max(sg[l], sg[now] + 1);
        }
        if (pw[now] < pw[r])
        {
            q.push(r), sg[r] = max(sg[r], sg[now] + 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        tot += sg[i];
    }
    cout << tot << endl;
    return 0;
}