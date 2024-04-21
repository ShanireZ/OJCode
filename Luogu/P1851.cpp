#include <algorithm>
#include <iostream>
using namespace std;
int ysh(int x)
{
    int tot = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            tot += i;
            if (i != x / i && i != 1)
            {
                tot += x / i;
            }
        }
    }
    return tot;
}
int main()
{
    int s;
    cin >> s;
    while (true)
    {
        int fd = ysh(s);
        if (ysh(fd) == s && fd != s)
        {
            cout << s << " " << fd << endl;
            break;
        }
        s++;
    }
    return 0;
}