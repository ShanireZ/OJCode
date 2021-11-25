#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
struct Ice
{
    int x, y;
    int check;
    int state;
};
Ice ice[1005][1005];
queue<Ice> icecream;
int child[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n;
void make_ans(int a, int b, int &s, int &p)
{
    icecream.push(ice[a][b]);
    ice[a][b].check = 1;
    while (icecream.size() != 0)
    {
        int x = icecream.front().x;
        int y = icecream.front().y;
        s++;
        p += 4;
        for (int i = 0; i < 4; i++)
        {
            if (ice[x + child[i][0]][y + child[i][1]].state == 1)
            {
                p--;
                if (ice[x + child[i][0]][y + child[i][1]].check == 0)
                {
                    icecream.push(ice[x + child[i][0]][y + child[i][1]]);
                    ice[x + child[i][0]][y + child[i][1]].check = 1;
                }
            }
        }
        icecream.pop();
    }
}
int main()
{
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == '#')
            {
                ice[i][j].state = 1;
            }
            ice[i][j].x = i;
            ice[i][j].y = j;
        }
    }
    int s = -1, p = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ice[i][j].state == 1 && ice[i][j].check == 0)
            {
                int tmp_s = 0, tmp_p = 0;
                make_ans(i, j, tmp_s, tmp_p);
                if (s < tmp_s)
                {
                    s = tmp_s;
                    p = tmp_p;
                }
                else if (s == tmp_s)
                {
                    p = min(p, tmp_p);
                }
            }
        }
    }
    cout << s << " " << p;
    return 0;
}