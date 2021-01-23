#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
int nums[100005];
void quick_sort(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int i = l, j = r;
    int st = nums[rand() % (r - l + 1) + l];
    while (i <= j)
    {
        while (nums[i] < st)
        {
            i++;
        }
        while (nums[j] > st)
        {
            j--;
        }
        if (i <= j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    quick_sort(l, j);
    quick_sort(i, r);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    srand((int)time(0));
    quick_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}