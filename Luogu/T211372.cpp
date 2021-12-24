#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int read();
struct Stu
{
    char name[25];
    int tot, id;
    bool operator<(const Stu oth) const
    {
        if (tot == oth.tot)
        {
            return id < oth.id;
        }
        return tot > oth.tot;
    }
};
Stu stus[105];
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        stus[i].id = i;
        scanf("%s", stus[i].name + 1);
        int a = read(), b = read();
        b = ceil(sqrt(b) * 10);
        stus[i].tot = round(0.4 * a + 0.6 * b);
    }
    sort(stus + 1, stus + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        printf("%s %d\n", stus[i].name + 1, stus[i].tot);
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}