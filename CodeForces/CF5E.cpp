#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
stack<pair<int, long long>> stk;
int a[1000005], b[1000005], n, pos, mxp;
long long tt, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == a[mxp])
        {
            tt++;
        }
        else if (a[i] > a[mxp])
        {
            mxp = i, tt = 1;
        }
    }
    for (int i = mxp; i <= n; i++)
    {
        b[++pos] = a[i];
    }
    for (int i = 1; i < mxp; i++)
    {
        b[++pos] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long t = 1;
        while (stk.size() && stk.top().first <= b[i])
        {
            ans += stk.top().second; // 栈顶和当前数配对
            if (b[i] == stk.top().first)
            {
                t += stk.top().second;
            }
            stk.pop();
        }
        ans += (stk.size() != 0); // 当前数和左侧比他大的数配对
        stk.push({b[i], t});
    }
    if (tt == 1) // 仅有一个最大值，栈中倒数第二个数已经计算过和最大值的配对了，例如题目样例
    {
        while (stk.size() > 2)
        {
            ans += stk.top().second;
            stk.pop();
        }
    }
    else
    {
        while (stk.size() > 1)
        {
            ans += stk.top().second;
            stk.pop();
        }
    }
    cout << ans << endl;
    return 0;
}