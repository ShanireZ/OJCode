#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Quest
{
    int start, last;
};
Quest quests[10005];
int dp[10005];     //記錄從n到i時刻的最大空餘時間
int amount[10005]; //記錄第i刻的任務數量
bool cmp(Quest a, Quest b)
{
    return a.start > b.start;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> quests[i].start >> quests[i].last;
        amount[quests[i].start]++;
    }
    sort(quests, quests + k, cmp);
    int id = 0; //任務排序後的編號
    for (int i = n; i >= 1; i--)
    {
        if (amount[i] == 0)
        {
            dp[i] = dp[i + 1] + 1;
        }
        else
        {
            for (int j = 1; j <= amount[i]; j++)
            {
                dp[i] = max(dp[i], dp[i + quests[id].last]);
                id++;
            }
        }
    }
    cout << dp[1];
    return 0;
}