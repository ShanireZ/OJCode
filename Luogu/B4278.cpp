#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string s;
vector<int> nums, ops;
int main()
{
    getline(cin, s);
    s += '+', nums.emplace_back(0);
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && (s[i] > '9' || s[i] < '0'))
        {
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9')
        {
            nums.back() = nums.back() * 10 + s[i] - '0';
        }
        else
        {
            if (ops.size() && ops.back() == 3)
            {
                int x = nums.back();
                nums.pop_back(), ops.pop_back();
                nums.back() *= x;
            }
            else if (ops.size() && ops.back() == 4)
            {
                int x = nums.back();
                nums.pop_back(), ops.pop_back();
                nums.back() /= x;
            }
            if (s[i] == '+')
            {
                ops.emplace_back(1);
            }
            else if (s[i] == '-')
            {
                ops.emplace_back(2);
            }
            else if (s[i] == '*')
            {
                ops.emplace_back(3);
            }
            else if (s[i] == '/')
            {
                ops.emplace_back(4);
            }
            nums.emplace_back(0);
        }
    }
    int ans = nums[0];
    for (int i = 0; i < (int)ops.size() - 1; i++)
    {
        if (ops[i] == 1)
        {
            ans += nums[i + 1];
        }
        else if (ops[i] == 2)
        {
            ans -= nums[i + 1];
        }
    }
    cout << ans << endl;
    return 0;
}