#include <algorithm>
#include <iostream>
using namespace std;
int nums[50], pos;
bool check(int x)
{
    pos = 0;
    while (x)
    {
        nums[++pos] = x % 8;
        x /= 8;
    }
    for (int i = 1; i <= pos / 2; i++)
    {
        if (nums[i] != nums[pos - i + 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        if (check(i * i))
        {
            cout << i * i << " ";
        }
    }
    return 0;
}