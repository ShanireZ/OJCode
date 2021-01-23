#include <iostream>
#include <algorithm>
using namespace std;
int prime[100005];
void makep(int max)
{
    for (int i = 2; i <= max / 2 + 1; i++)
    {
        for (int j = 2; i * j <= max; j++)
        {
            prime[i * j] = 1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    prime[0] = prime[1] = 1;
    makep(100000);
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if (prime[num] == 0)
        {
            cout << num << " ";
        }
    }
    return 0;
}