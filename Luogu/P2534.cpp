#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int ans[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
int now[20];
int mins, trig, n;
vector<int> ls;
void makels()
{
    sort(ls.begin(), ls.end());
    for (int i = 1; i <= n; i++)
    {
        vector<int>::iterator it = lower_bound(ls.begin(), ls.end(), now[i]);
        now[i] = it - ls.begin() + 1;
    }
}
int check()
{
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (abs(now[i] - now[i + 1]) != 1)
        {
            tot++;
        }
    }
    return tot;
}
void dfs(int step, int pre)
{
    if (check() == 0) //达成
    {
        trig = 1;
        return;
    }
    if (check() + step > mins) //超过上限
    {
        return;
    }
    //遍历
    for (int i = 2; i <= n; i++)
    {
        if (i == pre)
        {
            continue;
        }
        reverse(now + 1, now + 1 + i);
        dfs(step + 1, i);
        reverse(now + 1, now + 1 + i);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> now[i];
        ls.push_back(now[i]);
    }
    makels();
    now[n + 1] = n + 1;
    while (1)
    {
        dfs(0, 0);
        if (trig)
        {
            cout << mins;
            break;
        }
        mins++;
    }
    return 0;
}