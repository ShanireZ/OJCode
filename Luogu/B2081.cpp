#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int tot = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 7 != 0 && i % 10 != 7 && i / 10 != 7)
        {
            tot += i * i;
        }
    }
    cout << tot << endl;
    return 0;
}