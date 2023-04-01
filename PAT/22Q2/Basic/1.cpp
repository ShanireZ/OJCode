#include <iostream>
#include <string>
using namespace std;
string nums[15] = {"1011111", "0000011", "1110110", "1110011", "0101011", "1111001", "1111101", "1000011", "1111111", "1111011"};
int main()
{
    int ans = 0;
    for (int k = 1; k <= 2; k++)
    {
        int n = 0;
        string now;
        for (int i = 1; i <= 5; i++)
        {
            cin >> now;
            for (int j = 0; j < 10; j++)
            {
                if (now == nums[j])
                {
                    n = n * 10 + j;
                    break;
                }
            }
        }
        ans += n;
    }
    cout << ans;
    return 0;
}