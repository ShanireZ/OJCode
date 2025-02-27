#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
char ch;
int dis[105][105], way[105][105], n;
queue<pair<int, int>> q;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = 0x3f3f3f3f;
            cin >> ch;
            if (ch != '-')
            {
                way[i][j] = ch, dis[i][j] = 1, q.push(make_pair(i, j));
            }
        }
        dis[i][i] = 0, q.push(make_pair(i, i));
    }
    while (q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++)
            {
                if (way[i][x] == way[y][j] && way[i][x] != 0 && way[y][j] != 0 && dis[i][j] > dis[x][y] + 2)
                {
                    dis[i][j] = dis[x][y] + 2;
                    q.push(make_pair(i, j));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (dis[i][j] == 0x3f3f3f3f ? -1 : dis[i][j]) << " ";
        }
        cout << endl;
    }
    return 0;
}