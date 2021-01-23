#include <iostream>
using namespace std;
int save[205][10];
int nums(int n, int k)
{
    if (save[n][k] != 0)
    {
        return save[n][k];
    }
    if (n < k)
    {
        return nums(n, n);
    }
    if (n <= 1 || k <= 1)
    {
        return 1;
    }
    save[n][k] = nums(n, k - 1) + nums(n - k, k);
    return save[n][k];
}
int main()
{
    int n, k;
    cin >> n >> k;
    //放苹果升级版，只需进行一步预操作
    //题目要求将n个苹果放入k个盘子中，不允许空盘
    //说明每个盘子至少一个苹果，等同于从每个盘子中拿走一个苹果并允许此时空盘
    //等同于将n-k个苹果放入k个盘子中，允许空盘
    //后续等同与放苹果问题
    n -= k;
    cout << nums(n, k);
    return 0;
}