#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        cnt += (a % 9 == 0 && a % 8 != 0);
    }
    cout << cnt << endl;
    return 0;
}