#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
    int x, y, type, usd;
};
Node ice[1005][1005];
int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<Node> q;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '#')
            {
                ice[i][j].type = 1;
            }
            ice[i][j].x = i;
            ice[i][j].y = j;
        }
    }
    int maxs = -1, maxp = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ice[i][j].type == 1 && ice[i][j].usd == 0)
            {
                int s = 0, p = 0;
                ice[i][j].usd = 1;
                q.push(ice[i][j]);
                while (q.size() > 0)
                {
                    s++;
                    p += 4;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = q.front().x + moves[k][0];
                        int y = q.front().y + moves[k][1];
                        if (ice[x][y].type == 1)
                        {
                            p--;
                            if (ice[x][y].usd == 0)
                            {
                                ice[x][y].usd = 1;
                                q.push(ice[x][y]);
                            }
                        }
                    }
                    q.pop();
                }
                if (s > maxs || (s == maxs && p < maxp))
                {
                    maxs = s;
                    maxp = p;
                }
            }
        }
    }
    cout << maxs << " " << maxp;
    return 0;
}