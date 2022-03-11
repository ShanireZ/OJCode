#include <iostream>
using namespace std;
int py[10][5] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char dt[105][105];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> dt[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dt[i][j] == '*') //是地雷
            {
                cout << '*';
            }
            else
            {
                int tot = 0;
                for (int a = 0; a < 8; a++)
                {
                    int ni = i + py[a][0], nj = j + py[a][1];
                    if (dt[ni][nj] == '*')
                    {
                        tot++;
                    }
                }
                cout << tot;
            }
        }
        cout << endl;
    }
    return 0;
}