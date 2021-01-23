#include <bits/stdc++.h>
using namespace std;

long long Fun(long long a)
{
    long long total = 1;
    for (int i = 1; i <= a; i++)
    {
        total *= i;
    }
    return total;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    cout << Fun(n) / (Fun(m) * Fun(n - m));
    return 0;
}