#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
long long read()
{
    long long ans = 0;
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
struct Node
{
    char name[15];
    long long w;
    bool operator<(const Node &oth) const
    {
        return w > oth.w;
    }
};
Node h[100005], s[100005];
int main()
{
    int n = read(), m = read(), ph = 0, ps = 0;
    char name[15], op[5];
    for (int i = 1; i <= n + m; i++)
    {
        scanf("%s %s", name, op);
        if (op[0] == 'S')
        {
            strcpy(s[++ps].name, name);
            s[ps].w = read();
        }
        else
        {
            strcpy(h[++ph].name, name);
            h[ph].w = read();
        }
    }
    sort(s + 1, s + 1 + ps), sort(h + 1, h + 1 + ph);
    printf("%s\n", h[3].name);
    for (int i = 6; i < 10; i++)
    {
        printf("%s\n", s[i].name);
    }
    return 0;
}