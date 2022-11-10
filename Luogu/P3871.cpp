#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
priority_queue<int, vector<int>, greater<int>> up;
priority_queue<int, vector<int>, less<int>> down;
int read();
int main()
{
    int n = read();
    int sz = (n + 1) / 2 - 1; // n个数时down中元素个数 此时up的堆顶为中位数
    for (int i = 1; i <= n; i++)
    {
        down.push(read());
        if (int(down.size()) > sz)
        {
            up.push(down.top());
            down.pop();
        }
    }
    int m = read();
    for (int i = 1; i <= m; i++)
    {
        string opt;
        cin >> opt;
        if (opt == "add")
        {
            n++;
            sz = (n + 1) / 2 - 1;
            if (int(down.size()) < sz)
            {
                down.push(up.top());
                up.pop();
            }
            down.push(read());
            if (int(down.size()) > sz)
            {
                up.push(down.top());
                down.pop();
            }
        }
        else
        {
            printf("%d\n", up.top());
        }
    }
    return 0;
}
int read()
{
    int ans = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * f;
}