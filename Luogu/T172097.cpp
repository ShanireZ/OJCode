#include <iostream>
using namespace std;
long long stu[1005];
int main()
{
    int n, k, tot = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> stu[i];
        for (int j = 1; j < i; j++)
        {
            if (stu[i] * stu[j] <= k)
            {
                tot++;
            }
        }
    }
    cout << tot;
    return 0;
}