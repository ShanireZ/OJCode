#include <iostream>
#include <string>
using namespace std;
int s, t, w, cnt, usd[50];
char chs[50];
void dfs(int pos)
{
    if (pos == w)
    {
        cnt++;
        if (cnt > 1)
        {
            cout << chs << endl;
        }
        return;
    }
    int st = s - 1, ed = t - 1;
    if (pos != 0)
    {
        st = max(st, chs[pos - 1] - 'a');
    }
    for (int i = st; i <= ed; i++)
    {
        if ('a' + i < chs[pos] || usd[i])
        {
            continue;
        }
        chs[pos] = 'a' + i, usd[i] = 1;
        dfs(pos + 1);
        chs[pos] = 0, usd[i] = 0;
        if (cnt == 6)
        {
            return;
        }
    }
}
int main()
{
    cin >> s >> t >> w >> chs;
    dfs(0);
    return 0;
}