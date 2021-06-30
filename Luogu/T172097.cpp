#include <iostream>
#include <algorithm>
using namespace std;
long long stu[1005];
int main()
{
    int n, k, tot = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> stu[i];
    }
    sort(stu + 1, stu + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (stu[i] * stu[j] > k)
            {
                break;
            }
            tot++;
        }
    }
    cout << tot;
    return 0;
}