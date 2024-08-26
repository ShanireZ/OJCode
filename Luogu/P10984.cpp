#include <algorithm>
#include <iostream>
using namespace std;
string nums[20] = {"1111110", "0110000", "1101101", "1111001", "0110011",
                   "1011011", "1011111", "1110000", "1111111", "1111011"};
string res[20] = {"0000011", "1001011", "0000001", "0100001", "0101011",
                  "0110110", "1111111", "0010110", "0101001", "0010110",
                  "1011100", "0100110", "1010000", "0010011", "0001111",
                  "0101101", "0110101", "1101010"};
int main()
{
    long long ans = 1;
    for (int i = 0; i < 18; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 10; j++)
        {
            int ok = 1;
            for (int k = 0; k < 7; k++)
            {
                if (res[i][k] == '1' && nums[j][k] == '0')
                {
                    ok = 0;
                    break;
                }
            }
            cnt += ok;
        }
        ans *= cnt;
    }
    cout << ans << endl;
    return 0;
}