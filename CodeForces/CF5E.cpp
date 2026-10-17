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
            ans += stk.top().second; // 棧頂和當前數配對
            if (b[i] == stk.top().first)
            {
                t += stk.top().second;
            }
            stk.pop();
        }
        ans += (stk.size() != 0); // 當前數和左側比他大的數配對
        stk.push({b[i], t});
    }
    if (tt == 1) // 僅有一個最大值，棧中倒數第二個數已經計算過和最大值的配對了，例如題目範例
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