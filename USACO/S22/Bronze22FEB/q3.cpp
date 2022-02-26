#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int usd[5], trig;
vector<char> blk[5];
string ans;
void dfs(int pos)
{
    if (pos == ans.size())
    {
        cout << "YES" << endl;
        trig = 0;
        return;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (usd[i])
        {
            continue;
        }
        for (int j = 0; j < 6; j++)
        {
            if (blk[i][j] == ans[pos])
            {
                usd[i] = 1;
                dfs(pos + 1);
                usd[i] = 0;
            }
            if (trig == 0)
            {
                return;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            char ch;
            cin >> ch;
            blk[i].push_back(ch);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        memset(usd, 0, sizeof(usd));
        cin >> ans;
        trig = 1;
        dfs(0);
        if (trig)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}