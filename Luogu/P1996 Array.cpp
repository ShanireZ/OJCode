#include <iostream>
using namespace std;
int no[105];
int main()
{
    int n, m;
    cin >> n >> m;
    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        while (cnt != m)
        {
            now++;
            if (now > n)
            {
                now = 1;
            }
            if (no[now] == 0)
            {
                cnt++;
            }
        }
        cout << now << " ";
        no[now] = 1;
    }
    return 0;
}