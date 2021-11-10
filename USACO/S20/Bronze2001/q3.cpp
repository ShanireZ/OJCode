#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;
long long all[100005];
int main()
{
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    ios::sync_with_stdio(false);
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= 100000; i++)
    {
        all[i] = all[i - 1] + i; //每个速度的加速起步距离
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 100000; j >= 1; j--)
        {
            long long dis = all[j]; //最小行进距离
            if (j > x)              //回落距离
            {
                dis += all[j - 1] - all[x - 1];
            }
            if (dis <= k) //没跑过头 此速度可行
            {
                int times = j; //最小行进时间
                if (j > x)     //回落时间
                {
                    times += j - x;
                }
                dis = k - dis;                //仍需前进距离
                times += ceil(1.0 * dis / j); //仍需前进的最短时间
                cout << times << endl;
                break;
            }
        }
    }
    return 0;
}