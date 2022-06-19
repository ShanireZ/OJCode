#include <iostream>
#include <queue>
#include <set>
using namespace std;
int n, m, ind[30], last[30], to[1000], pre[1000];
bool check(int id)
{
    queue<int> q;
    int dp[30] = {0}, td[30], cnt = 0;
    for (int i = 0; i < n; i++)
    {
        td[i] = ind[i];
        if (td[i] == 0)
        {
            q.push(i);
            dp[i] = 1, cnt++;
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = last[now]; i != 0; i = pre[i])
        {
            int nxt = to[i];
            td[nxt]--;
            if (td[nxt] == 0)
            {
                dp[nxt] = dp[now] + 1;
                q.push(nxt), cnt++;
            }
        }
    }
    if (cnt != n) // 2 个数不足 图中有环
    {
        cout << "Inconsistency found after " << id << " relations." << endl;
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] != n)
        {
            continue;
        }
        cout << "Sorted sequence determined after " << id << " relations: "; // 1 层数够了
        for (int j = n; j >= 1; j--)
        {
            for (int k = 0; k < n; k++)
            {
                if (dp[k] == j)
                {
                    cout << char('A' + k);
                    break;
                }
            }
        }
        cout << "." << endl;
        return true;
    }
    return false;
}
int main()
{

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        char v, u;
        cin >> v >> u >> u;
        int x = u - 'A', y = v - 'A';
        to[i] = y, pre[i] = last[x];
        last[x] = i, ind[y]++;
        if (check(i))
        {
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined." << endl; // 3 无回流但层数不够
    return 0;
}