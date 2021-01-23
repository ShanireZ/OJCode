#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int read();
struct Step
{
    int v, lpos, rpos;
    char op;
};
Step steps[100005];
vector<int> ls;
int vis[100005];
int main()
{
    int n = read(), k = read();
    int cur = 0;
    ls.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        steps[i].v = read();
        scanf("%c", &steps[i].op);
        if (steps[i].op == 'R')
        {
            steps[i].lpos = cur;
            cur += steps[i].v;
            steps[i].rpos = cur;
        }
        else
        {
            steps[i].rpos = cur;
            cur -= steps[i].v;
            steps[i].lpos = cur;
        }
        ls.push_back(cur);
    }
    sort(ls.begin(), ls.end());
    unique(ls.begin(), ls.end());
    for (int i = 1; i <= n; i++)
    {
        int st = lower_bound(ls.begin(), ls.end(), steps[i].lpos) - ls.begin();
        int ed = lower_bound(ls.begin(), ls.end(), steps[i].rpos) - ls.begin();
        vis[st]++;
        vis[ed]--;
    }
    int cnt = 0, tot = 0;
    for (int i = 0; i < ls.size(); i++)
    {
        if (cnt >= k)
        {
            tot += ls[i] - ls[i - 1];
        }
        cnt += vis[i];
    }
    printf("%d", tot);
    return 0;
}
int read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    int t = 1, n = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}