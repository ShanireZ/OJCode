#include <iostream>
using namespace std;
int c1[100005][3], c2[100005][3], trs[100005][3][3];
void init(string a, string b)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        a[i] = (a[i] == 'A' ? 0 : (a[i] == 'C' ? 1 : 2));
        b[i] = (b[i] == 'A' ? 0 : (b[i] == 'C' ? 1 : 2));
    }
    trs[0][a[0]][b[0]] = 1, c1[0][a[0]] = 1, c2[0][b[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c1[i][j] = c1[i - 1][j], c2[i][j] = c2[i - 1][j];
            for (int k = 0; k < 3; k++)
            {
                trs[i][j][k] = trs[i - 1][j][k];
            }
        }
        c1[i][a[i]]++, c2[i][b[i]]++, trs[i][a[i]][b[i]]++;
    }
}
int get_distance(int x, int y)
{
    for (int i = 0; i < 3; i++)
    {
        if (c1[y][i] - c1[x - 1][i] != c2[y][i] - c2[x - 1][i])
        {
            return -1;
        }
    }
    int trss[3][3] = {0}, res = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            trss[i][j] = trs[y][i][j] - trs[x - 1][i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                continue;
            }
            int t = min(trss[i][j], trss[j][i]);
            res += t, trss[i][j] -= t, trss[j][i] -= t;
        }
    }
    return res + (trss[1][2] + trss[2][1]) * 2;
}