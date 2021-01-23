#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Num
{
    int pos, num, rank;
};

bool cmp_num(Num a, Num b)
{
    return a.num < b.num;
}

bool cmp_pos(Num a, Num b)
{
    return a.pos < b.pos;
}

int main()
{
    int n;
    cin >> n;
    Num nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i].num;
        nums[i].pos = i;
    }
    sort(nums, nums + n, cmp_num);
    nums[0].rank = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i].num == nums[i - 1].num)
        {
            nums[i].rank = nums[i - 1].rank;
        }
        else
        {
            nums[i].rank = nums[i - 1].rank + 1;
        }
    }
    sort(nums, nums + n, cmp_pos);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i].rank + 1 << " ";
    }
    return 0;
}