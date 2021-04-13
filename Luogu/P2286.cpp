#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
set<int> house;
int type, n, mod = 1000000, tot;
int read();
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        int a = read(), b = read();
        if (house.size() == 0 || (house.size() != 0 && type == a))
        {
            type = a;
            house.insert(b);
        }
        else
        {
            set<int>::iterator itr = house.lower_bound(b);
            set<int>::iterator itl = itr;
            if (itr == house.end())
            {
                itr--;
            }
            if (itl != house.begin())
            {
                itl--;
            }
            if (abs(*itl - b) <= abs(*itr - b))
            {
                tot = (tot + abs(*itl - b) % mod) % mod;
                house.erase(itl);
            }
            else
            {
                tot = (tot + abs(*itr - b) % mod) % mod;
                house.erase(itr);
            }
        }
    }
    printf("%d", tot);
    return 0;
}
int read()
{
    int ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}