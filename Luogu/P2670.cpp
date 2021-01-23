#include <iostream>
#include <string>
using namespace std;
char maps[105][105];
int nums[105][105];
int moves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> maps[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (maps[i][j] == '*')
            {
                nums[i][j] = -1;
            }
            else
            {
                int tot = 0;
                for (int k = 0; k < 8; k++)
                {
                    int nx = i + moves[k][0];
                    int ny = j + moves[k][1];
                    if (maps[nx][ny] == '*')
                    {
                        tot++;
                    }
                }
                nums[i][j] = tot;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (nums[i][j] == -1)
            {
                cout << '*';
            }
            else
            {
                cout << nums[i][j];
            }
        }
        cout << endl;
    }
}