#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int total = 1;               //1只有1個約數
    for (int i = 2; i <= n; i++) //從2開始計算有多少個約數
    {
        int tmp = i;
        int ans = 1; //儲存當前數字i的約數個數
        while (tmp != 1)
        {
            bool trig = 1;                     //判斷現解段所剩數字是否為質數
            for (int j = 2; j * j <= tmp; j++) //找質因數
            {
                int times = 0; //當前質因數j出現次數
                while (tmp % j == 0)
                {
                    tmp = tmp / j;
                    trig = 0;
                    times++;
                }
                if (trig == 0) //所剩數字不為質數
                {
                    ans *= (times + 1); //如果i = p1^a1 * p2 ^ a2 ... 且p1 p2...都為質數 那麼i的約數個數為(a1+1) * (a2+!) * ...
                }
            }
            if (trig) //所剩數字為質數
            {
                ans *= 2;
                tmp = 1;
            }
        }
        total += ans;
    }
    cout << total;
    return 0;
}