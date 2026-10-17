#include <iostream>
#include <set>
#include <queue>
using namespace std;
set<int> s;
priority_queue<int> q;
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) //統計每一個親戚所在的位置
    {
        int x;
        cin >> x;
        x = x / 12 + 1;
        ans = max(ans, x); //首先傳送回最早的親戚那裡
        s.insert(x);
    }
    int pre = 0;
    for (auto it = s.begin(); it != s.end(); it++) //統計所有可以用時光機的間隔
    {
        int x = *it - pre - 1;
        if (x != 0)
        {
            q.push(x);
        }
        pre = *it;
    }
    for (int i = 1; i <= k - 1; i++) //選擇最大的k-1個間隔使用時光機
    {
        ans -= q.top();
        q.pop();
    }
    cout << ans * 12 << endl;
    return 0;
}