#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int tot = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        tot += i * i;
    }
    cout << tot << endl;
    return 0;
}