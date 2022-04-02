#include <iostream>
#include <string>
using namespace std;
int ch[500005][60], id[500005], t[500005], n, cnt;
int lowbit(int x)
{
    return x & -x;
}
void edit(int pos)
{
    while (pos <= n)
    {
        t[pos]++;
        pos += lowbit(pos);
    }
}
int query(int pos)
{
    int ans = 0;
    while (pos)
    {
        ans += t[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int now = 0;
        for (int j = 0; j < s.size(); j++)
        {
            int p = s[j] - 'A';
            if (ch[now][p] == 0)
            {
                ch[now][p] = ++cnt;
            }
            now = ch[now][p];
        }
        id[now] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int now = 0;
        for (int j = 0; j < s.size(); j++)
        {
            int p = s[j] - 'A';
            now = ch[now][p];
        }
        ans += query(n) - query(id[now]);
        edit(id[now]);
    }
    cout << ans << endl;
    return 0;
}