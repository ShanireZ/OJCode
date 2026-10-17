#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int t[1000005];   //每個數字輸出的次數
int ans[1000005]; //每個數字可以拍幾下其他牛
int all[100005];  //每個牛手中數字是多少
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
        int num = all[i]; //當前數字
        if (ans[num] == 0)
        {
            int maxn = sqrt(num);
            for (int j = 1; j <= maxn; j++) //找到num的所有約數
            {
                if (all[i] % j == 0)
                {
                    int id1 = j, id2 = all[i] / j;
                    ans[num] += t[id1] + t[id2]; //num可拍其所有約數
                    if (id1 == id2)              //兩個約數相同 把重複部分去除
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