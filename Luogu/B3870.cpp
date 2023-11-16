#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
long long a[100], pos, n;
int main()
{
    cin >> n;
    while (n)
    {
        a[++pos] = n % 2, n /= 2;
        if (pos % 8 == 7)
        {
            a[++pos] = 1;
        }
    }
    while (pos % 8 != 0)
    {
        pos++;
    }
    for (int i = 1; i <= pos; i += 8)
    {
        int tot = a[i + 4] + a[i + 5] * 2 + a[i + 6] * 4 + a[i + 7] * 8;
        char c = (tot < 10 ? tot + '0' : tot - 10 + 'A');
        cout << c;
        tot = a[i] + a[i + 1] * 2 + a[i + 2] * 4 + a[i + 3] * 8;
        c = (tot < 10 ? tot + '0' : tot - 10 + 'A');
        cout << c << " ";
    }
    if (pos == 0)
    {
        cout << "00";
    }
    return 0;
}