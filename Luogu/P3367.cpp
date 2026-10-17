#include <iostream>
#include <algorithm>
using namespace std;
int nums[10005];          //每個數都在哪個組
int groups[10005][10005]; //每個組都有誰

void merge(int a, int b) //並組
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
    for (int i = 0; i <= 10004; i++) //初始化每個數一組 且每組只有自己
    {
        nums[i] = i;
        groups[i][0] = 1;
        groups[i][1] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) //需要合併小組
        {
            if (nums[x] != nums[y])
            {
                merge(x, y);
            }
        }
        else if (z == 2) //查詢是否是一組
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