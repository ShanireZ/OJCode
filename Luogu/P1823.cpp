#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
stack<pair<int, int>> stk;
int main()
{
    long long ans = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, t = 1;
        cin >> x;
        while (stk.size() && stk.top().first <= x)
        {
            ans += stk.top().second;  // 嘗試和前方小於等於該數的元素配對
            if (stk.top().first == x) // 更新相同數字的次數
            {
                t += stk.top().second;
            }
            stk.pop();
        }
        ans += (stk.size() != 0); // 嘗試和前方大數配對
        stk.push({x, t});
    }
    cout << ans << endl;
    return 0;
}