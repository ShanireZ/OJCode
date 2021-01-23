#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += i;
    }
    cout << tot;
    return 0;
}