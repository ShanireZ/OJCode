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
    //放蘋果升級版，只需進行一步預操作
    //題目要求將n個蘋果放入k個盤子中，不允許空盤
    //說明每個盤子至少一個蘋果，等同於從每個盤子中拿走一個蘋果並允許此時空盤
    //等同於將n-k個蘋果放入k個盤子中，允許空盤
    //後續等同與放蘋果問題
    n -= k;
    cout << nums(n, k);
    return 0;
}