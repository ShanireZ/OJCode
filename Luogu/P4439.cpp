#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, res = 1;
    cin >> n;
    char pre = '#';
    while (n--)
    {
        char ch;
        cin >> ch;
        if (ch != pre)
        {
            pre = ch, res++;
        }
    }
    cout << res << endl;
    return 0;
}