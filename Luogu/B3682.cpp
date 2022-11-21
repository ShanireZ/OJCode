#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
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
unordered_map<string, pair<int, int>> tp;
int score[10] = {0, 2000, 1000, 200, 36, 6}, ans;
int main()
{
    int n = read(), k = read(), op;
    string name;
    name.resize(15);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s %d", &name[0], &op);
        tp[name] = make_pair(op, 0);
    }
    for (int i = 1; i <= k; i++)
    {
        scanf("%s", &name[0]);
        tp[name].second++;
        if (tp[name].second > 1)
        {
            ans += score[tp[name].first];
        }
    }
    printf("%d\n", ans);
    return 0;
}