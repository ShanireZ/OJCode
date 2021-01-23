#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Herb
{
    int v, t;
};
Herb herbs[10005];
int check[100005];     //完全背包问题
void sum(int a, int b) //前a个草药采集时间不超过b时，最大的总价值
{
    if (b >= herbs[a].t)
    {
        for (int i = herbs[a].t; i <= b; i++)
        {
            check[i] = max(check[i], check[i - herbs[a].t] + herbs[a].v);
        }
    }
}
int main()
{
    int time, type;
    cin >> time >> type;
    for (int i = 1; i <= type; i++)
    {
        cin >> herbs[i].t >> herbs[i].v;
    }
    for (int i = 1; i <= type; i++)
    {
        sum(i, time);
    }
    cout << check[time];
    return 0;
}