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
            ans += stk.top().second;  // 尝试和前方小于等于该数的元素配对
            if (stk.top().first == x) // 更新相同数字的次数
            {
                t += stk.top().second;
            }
            stk.pop();
        }
        ans += (stk.size() != 0); // 尝试和前方大数配对
        stk.push({x, t});
    }
    cout << ans << endl;
    return 0;
}