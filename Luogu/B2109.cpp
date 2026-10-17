#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    char x;
    int cnt = 0;
    while (cin >> x)
    {
        // todo 統計數字字元的個數
        if (x >= '0' && x <= '9')
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}