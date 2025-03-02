#include <algorithm>
#include <iostream>
using namespace std;
long long n;
void write(unsigned __int128 x)
{
    if (x > 9)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}
int main()
{
    cin >> n;
    unsigned __int128 ans = 1;
    ans = ans * n * (n + 1) * (n * 2 + 1) / 6;
    write(ans);
    return 0;
}