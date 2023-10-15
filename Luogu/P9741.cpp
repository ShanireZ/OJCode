#include <algorithm>
#include <iostream>
using namespace std;
int a[2000005], t[2000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[i] = (n - i + 1) % 2;
    }
    int now = n;
    while (now > 0)
    {
        cout << (t[now] ? !a[now] : a[now]) << " ";
        now -= 2;
    }
    now = (n % 2 == 0 ? 1 : 2);
    while (now < n)
    {
        cout << (t[now] ? !a[now] : a[now]) << " ";
        now += 2;
    }
    cout << endl;
    return 0;
}