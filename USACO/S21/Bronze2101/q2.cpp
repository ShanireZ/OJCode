#include <iostream>
using namespace std;
int main()
{
    int j = 0, o = 0, n, ans;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        (x % 2 == 0) ? o++ : j++;
    }
    while (o < j)
    {
        o++;
        j -= 2;
    }
    if (o > j + 1)
    {
        o = j + 1;
    }
    cout << o + j << endl;
    return 0;
}