#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int pre, ans = 1, maxa = 1;
    cin >> pre;
    for (int i = 2; i <= n; i++)
    {
        int num;
        cin >> num;
        if (num - pre == 1)
        {
            ans++;
        }
        else
        {
            ans = 1;
        }
        maxa = max(maxa, ans);
        pre = num;
    }
    cout << maxa;
    return 0;
}