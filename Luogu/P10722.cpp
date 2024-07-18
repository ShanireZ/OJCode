#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> to[100005];
int col[100005], t[100005], n, q, x;
string s;
void dfs(int now)
{
    col[now] = (col[now] + t[now]) % 2;
    for (int nxt : to[now])
    {
        t[nxt] += t[now];
        dfs(nxt);
    }
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        to[x].push_back(i);
    }
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        col[i] = s[i - 1] - '0';
    }
    cin >> q;
    while (q--)
    {
        cin >> x;
        t[x]++;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << col[i];
    }
    return 0;
}