#include <algorithm>
#include <iostream>
using namespace std;
int n, k, pre[1000005];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        pre[x] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n / k; j++)
        {
            int x;
            cin >> x;
            cnt += pre[x];
        }
        if (cnt != 1)
        {
            cout << "\\QAQ/" << endl;
            return 0;
        }
    }
    cout << "\"MiaoW\"" << endl;
    return 0;
}