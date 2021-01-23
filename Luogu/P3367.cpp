#include <iostream>
#include <algorithm>
using namespace std;
int nums[10005];          //每个数都在哪个组
int groups[10005][10005]; //每个组都有谁

void merge(int a, int b) //并组
{
    int l = min(nums[a], nums[b]);
    int r = max(nums[a], nums[b]);
    for (int i = 1; i <= groups[r][0]; i++)
    {
        groups[l][++groups[l][0]] = groups[r][i];
        nums[groups[r][i]] = l;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= 10004; i++) //初始化每个数一组 且每组只有自己
    {
        nums[i] = i;
        groups[i][0] = 1;
        groups[i][1] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) //需要合并小组
        {
            if (nums[x] != nums[y])
            {
                merge(x, y);
            }
        }
        else if (z == 2) //查询是否是一组
        {
            if (nums[x] == nums[y])
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}