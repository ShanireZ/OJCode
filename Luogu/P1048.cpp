#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Herb
{
    int v, t;
};
Herb herbs[105];      //01背包问题
int check[105][1005]; //存储前a个草药采集时间不超过b时，最大的总价值
int sum(int a, int b)
{
    if (check[a][b] == -1)
    {
        if (b < herbs[a].t)
        {
            check[a][b] = sum(a - 1, b);
        }
        else
        {
            check[a][b] = max(sum(a - 1, b), sum(a - 1, b - herbs[a].t) + herbs[a].v);
        }
    }
    return check[a][b];
}

int main()
{
    int time, type;
    cin >> time >> type;
    memset(check, -1, sizeof(check));
    for (int i = 1; i <= type; i++)
    {
        cin >> herbs[i].t >> herbs[i].v;
    }
    for (int i = 0; i <= time; i++)
    {
        check[0][i] = 0;
    }
    for (int i = 0; i <= type; i++)
    {
        check[i][0] = 0;
    }
    cout << sum(type, time);
    return 0;
}