#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
char chs[100005][15];
vector<int> pos[15];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> chs[i][j];
            if (chs[i][j] == '-')
            {
                pos[j].push_back(i);
            }
        }
    }
    for (int j = 1; j <= m; j++)
    {
        pos[j].push_back(n + 1);
    }
    for (int j = 1; j <= m; j++) // 寻找下方最近的非空
    {
        for (int i = n; i >= 1; i--)
        {
            if (chs[i][j] < 'A' || chs[i][j] > 'Z')
            {
                continue;
            }
            int p = lower_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin();
            char ch = chs[i][j];
            chs[i][j] = '.', pos[j][p]--;
            chs[pos[j][p]][j] = ch;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << chs[i][j];
        }
        cout << endl;
    }
    return 0;
}