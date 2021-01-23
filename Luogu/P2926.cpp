#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int t[1000005];   //每个数字输出的次数
int ans[1000005]; //每个数字可以拍几下其他牛
int all[100005];  //每个牛手中数字是多少
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> all[i];
        t[all[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        int num = all[i]; //当前数字
        if (ans[num] == 0)
        {
            int maxn = sqrt(num);
            for (int j = 1; j <= maxn; j++) //找到num的所有约数
            {
                if (all[i] % j == 0)
                {
                    int id1 = j, id2 = all[i] / j;
                    ans[num] += t[id1] + t[id2]; //num可拍其所有约数
                    if (id1 == id2)              //两个约数相同 把重复部分去除
                    {
                        ans[num] -= t[id2];
                    }
                    if (id2 == num) //不能自己拍自己
                    {
                        ans[num]--;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[all[i]] << endl;
    }
    return 0;
}