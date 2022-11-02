#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string str;
int len, cnt, co, ca, stk[1000005], nxt[1000005];
int search(int l, int r, char tar)
{
    while (l <= r && str[l] != tar)
    {
        if (str[l] == '(')
        {
            l = nxt[l];
        }
        l++;
    }
    return l;
}
int dfs(int l, int r, char tar)
{
    while (nxt[l] == r)
    {
        tar = '|', l++, r--;
    }
    if (l == r)
    {
        return str[l] - '0';
    }
    int pos = search(l, r, tar);
    int ans = dfs(l, pos - 1, '&'); // 处理左侧答案
    while (pos <= r)                // 处理右侧答案
    {
        int x = search(pos + 1, r, tar);
        if (str[pos] == '&' && ans == 0)
        {
            ca++;
        }
        else if (str[pos] == '|' && ans == 1)
        {
            co++;
        }
        else
        {
            ans = dfs(pos + 1, x - 1, '|');
        }
        pos = x;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    memset(nxt, -1, sizeof(nxt));
    cin >> str;
    len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            stk[++cnt] = i;
        }
        else if (str[i] == ')')
        {
            int pos = stk[cnt--];
            nxt[pos] = i;
        }
    }
    cout << dfs(0, len - 1, '|') << endl;
    cout << ca << " " << co << endl;
    return 0;
}