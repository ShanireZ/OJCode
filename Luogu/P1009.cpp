#include <iostream>
using namespace std;
int fact[100][100];
int cnt[100];
void mult(int x[100], int y[100]) //x*y结果存到y中
{
    int ans[200] = {0};
    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            ans[i + j - 1] += x[i] * y[j];
        }
    }
    for (int i = 1; i < 100; i++)
    {
        if (ans[i] >= 10)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
        y[i] = ans[i];
    }
}
void add(int x[100], int y[100]) //x+y结果存到y中
{
    for (int i = 1; i < 100; i++)
    {
        y[i] = x[i] + y[i];
        if (y[i] >= 10)
        {
            y[i + 1] += y[i] / 10;
            y[i] %= 10;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    fact[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fact[i][1] = i;
        mult(fact[i - 1], fact[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        add(fact[i], cnt);
    }
    int trig = 0;
    for (int i = 100; i > 0; i--)
    {
        if (cnt[i] == 0 && trig == 0)
        {
            continue;
        }
        trig = 1;
        cout << cnt[i];
    }
    return 0;
}