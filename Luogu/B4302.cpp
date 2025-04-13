#include <algorithm>
#include <iostream>
using namespace std;
int a[100005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cnt = 1, now = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            cnt++;
        }
        else
        {
            if (cnt % 2 == 1)
            {
                break;
            }
            cnt = 1, now = a[i];
        }
    }
    cout << now << endl;
    return 0;
}